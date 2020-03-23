#include "AssetManager.h"
#include "Vertex.h"

AssetManager::AssetManager()
{
	assets = std::map<std::string, Asset*>();
}

AssetManager::~AssetManager()
{
	assets.erase(assets.begin(), assets.end());
	assets.clear();
}

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

void AssetManager::AddAsset(std::string fileName, Asset* asset)
{
	assets.try_emplace(fileName, asset);
}

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