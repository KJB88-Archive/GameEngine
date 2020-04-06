#include "AssetManager.h"
#include "Vertex.h"

int AssetManager::idCount = 0;

AssetManager::AssetManager()
{
	assets = std::map<std::string, Asset*>();
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
	std::ifstream in(fileName);
	if (in)
	{
		// Get type
		int type = 0;
		in >> type;

		// Branch based on type
		switch (type)
		{
			// Mesh
		case 0:
			return CreateMesh(in);
		}
	}

	return false;
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
}

// Create Mesh asset
Mesh* AssetManager::CreateMesh(std::ifstream& stream)
{
	Mesh* mesh = new Mesh();
	idCount++;

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

	return mesh;
}