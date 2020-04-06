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

	static Asset* GetAsset(std::string fileName);

private:

	static int idCount;

	//bool CreateAsset(std::string fileName, Asset& asset);
	//bool CreateMesh(std::ifstream& stream, Asset& asset);

	// Asset creation
	static Asset* CreateAsset(std::string fileName);
	static Mesh* CreateMesh(std::ifstream& stream);
	//bool CreateScene(std::ifstream stream, Asset& asset);

	// Map Manipulation
	static void AddAsset(std::string fileName, Asset* asset);

	static ASSETMAP assets;
};