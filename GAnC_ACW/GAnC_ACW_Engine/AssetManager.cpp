#include "AssetManager.h"
#include "Vertex.h"
#include "Logger.h"
#include "Mesh.h"
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
			// Mesh
		case 1:
			asset = CreateMesh(in);
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