#define _USE_MATH_DEFINES

#include "AssetManager.h"
#include "Vertex.h"
#include "Logger.h"
#include "Mesh.h"

#include <cmath>
using namespace std;

int AssetManager::idCount = 0;
ASSETMAP AssetManager::assets = std::map<std::string, Asset*>();

AssetManager::AssetManager()
	: Manager("Asset")
{
}

AssetManager::~AssetManager()
{
	assets.erase(assets.begin(), assets.end());
	assets.clear();
}

// Load Asset type from file
// and pass stream to specific creation function
Asset* AssetManager::CreateAsset(std::string fileName)
{
	// Create stream to file
	std::ifstream in(fileName.c_str());
	Asset* asset = nullptr;

	if (in)
	{
		// Get type
		int type = 0;
		in >> type;

		// Branch based on type
		switch (type)
		{
		case 0:
			Logger::LogToConsole("ASSET MANAGER: Unknown asset type.");
			return NULL;

			// Mesh
		case 1:
			asset = CreateMesh(in);

			break;

			// SPHERICAL MESH
		case 2:
			asset = CreateSphereMesh(in);
			break;
		}
	}
	else
	{
		Logger::LogToConsole("ASSET MANAGER: Unable to open file: " + fileName);
	}

	CloseFileStream(in);
	return asset;
}

// Get the asset by file name and return as base Asset pointer
Asset* AssetManager::GetAsset(std::string fileName)
{
	ASSETMAP::const_iterator iterator = assets.find(fileName);

	// If no asset exists
	if (iterator == assets.end())
	{
		// Create one
		Asset* asset = CreateAsset(fileName);
		AddAsset(fileName, asset);
		return asset;
	}
	// Found Asset
	else
	{
		// Return id;
		return iterator->second;
	}

}

// Add asset to Asset collection
void AssetManager::AddAsset(std::string fileName, Asset* asset)
{
	assets.try_emplace(fileName, asset);
	idCount++;
}

void AssetManager::CloseFileStream(std::ifstream& stream)
{
	stream.close();
}

// Create Mesh asset
Mesh* AssetManager::CreateMesh(std::ifstream& stream)
{
	Mesh* mesh = new Mesh();

	// Vertices
	int numVertices;
	stream >> numVertices;
	
	for (int i = 0; i < numVertices; i++)
	{
		Vertex v;
		stream >> v.x; 
		stream >> v.y;
		stream >> v.z;

		stream >> v.r;
		stream >> v.g;
		stream >> v.b;
		stream >> v.a;

		mesh->AddVertex(v);
	}

	// Indices
	int numIndices;
	stream >> numIndices;

	int index;
	for (int i = 0; i < numIndices; i++)
	{
		stream >> index;
		mesh->AddIndex(index);
	}

	if (stream.fail())
	{
		// TODO - Add elegant handling of stream failure.
		Logger::LogToConsole("ASSET MANAGER: Filestream has failed.");
		return nullptr;
	}

	Logger::LogToConsole("ASSET MANAGER: Loaded Mesh file.");
	return mesh;
}

/// TYPE
/// STACKCOUNT
/// SLICECOUNT
/// STARTING VERT

/// SPHERE MESH LOADING BY ERIC RICHARDS
/// [02/05/2020]
/// http://www.richardssoftware.net/2013/07/shapes-demo-with-direct3d11-and-slimdx.html
// Create spherical mesh asset
Mesh* AssetManager::CreateSphereMesh(std::ifstream& stream)
{
	Mesh* mesh = new Mesh();

	int stackCount = 10;
	int sliceCount = 10;
	
	//// Get counts
	//stream >> stackCount;
	//stream >> sliceCount;

	//// Read in starting vert
	//Vertex v;
	//stream >> v.x;
	//stream >> v.y;
	//stream >> v.z;

	//stream >> v.r;
	//stream >> v.g;
	//stream >> v.b;
	//stream >> v.a;

	//mesh->AddVertex(v);

		// Get radius
	float radius = 1.0f;
	//stream >> radius;

	Vertex v = Vertex
	{
		0.0f, radius, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
	};
	mesh->AddVertex(v);

	// Calculate stack / slice step
	float phiStep = M_PI / stackCount;
	float thetaStep = 2.0f * M_PI / sliceCount;

	// Stack loop
	for (int i = 1; i <= stackCount - 1; ++i)
	{
		// Set phi
		float phi = i * phiStep;

		// Slice loop
		for (int j = 0; j <= sliceCount; ++j)
		{
			// Set theta
			float theta = j * thetaStep;

			// Calculate vertex position
			Vector3 p = Vector3(
				radius * sin(phi) * cos(theta),
				radius * cos(phi),
				radius * sin(phi) * sin(theta)
			);

			//Vector3 t = Vector3(
			//	-radius * sin(phi) * sin(theta),
			//	0.0f,
			//	radius * sin(phi) * cos(theta)
			//);

			// Update vertex position
			v.x = p.x;
			v.y = p.y;
			v.z = p.z;
			mesh->AddVertex(v);
		}
	}
	
	v.x = 0.0f;
	v.y = -radius;
	v.z = 0.0f;

	mesh->AddVertex(v);

	for (int i = 1; i <= sliceCount; ++i)
	{
		mesh->AddIndex(0);
		mesh->AddIndex(i + 1);
		mesh->AddIndex(i);
	}

	int baseIndex = 1;
	int ringVertexCount = sliceCount + 1;

	for (int i = 0; i < stackCount - 2; ++i)
	{
		for (int j = 0; j < sliceCount; ++j)
		{
			mesh->AddIndex(baseIndex + i * ringVertexCount + j);
			mesh->AddIndex(baseIndex + i * ringVertexCount + j + 1);
			mesh->AddIndex(baseIndex + (i + 1) * ringVertexCount + j);

			mesh->AddIndex(baseIndex + (i + 1) * ringVertexCount + j);
			mesh->AddIndex(baseIndex + i * ringVertexCount + j + 1);
			mesh->AddIndex(baseIndex + (i + 1) * ringVertexCount + j + +1);
		}
	}

	int southPoleIndex = mesh->NumVerts();
	baseIndex = southPoleIndex - ringVertexCount;

	for (int i = 0; i < sliceCount; ++i)
	{
		mesh->AddIndex(southPoleIndex);
		mesh->AddIndex(baseIndex + i);
		mesh->AddIndex(baseIndex + i + 1);
	}

	return mesh;
}