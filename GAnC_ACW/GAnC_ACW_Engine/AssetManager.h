#pragma once
#include "Asset.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
class Mesh;

#include "Manager.h"

typedef std::map<std::string, Asset*> ASSETMAP;

class AssetManager
	: Manager
{
public:

	enum AssetType
	{
		UNKNOWN = 0,
		MESH = 1,
		MESH_SPHERE = 2,

		// Other resources can go here,
		// such as audioClips, backgroundMusic, textures, shaders, etc
	};

	AssetManager();
	~AssetManager();

	// Simplified API call
	static Asset* GetAsset(std::string fileName);

private:

	static int idCount;

	//bool CreateAsset(std::string fileName, Asset& asset);
	//bool CreateMesh(std::ifstream& stream, Asset& asset);
	static void CloseFileStream(std::ifstream& stream);

	// Asset creation
	static Asset* CreateAsset(std::string fileName);
	static Mesh* CreateMesh(std::ifstream& stream);
	static Mesh* CreateSphereMesh(std::ifstream& stream);

	//bool CreateScene(std::ifstream stream, Asset& asset);

	// Map Manipulation
	static void AddAsset(std::string fileName, Asset* asset);

	static ASSETMAP assets;
};