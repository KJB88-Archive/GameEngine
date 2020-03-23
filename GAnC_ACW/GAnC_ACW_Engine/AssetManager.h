#pragma once
#include "Asset.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Mesh.h"

typedef std::map<std::string, Asset*> ASSETMAP;

class AssetManager
{
public:

	enum AssetType
	{
		MESH
		// Other resources can go here,
		// such as audioClips, backgroundMusic, textures, shaders, etc
	};

	AssetManager();
	~AssetManager();

	Asset* GetAsset(std::string fileName);

private:

	int idCount = 0;

	// Asset creation
	Asset* CreateAsset(std::string fileName);
	Mesh* CreateMesh(std::ifstream& stream);
	//bool CreateScene(std::ifstream stream, Asset& asset);

	// Map Manipulation
	void AddAsset(std::string fileName, Asset* asset);

	ASSETMAP assets;
};