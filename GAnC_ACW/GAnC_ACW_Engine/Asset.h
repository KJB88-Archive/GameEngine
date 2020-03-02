#pragma once
#include <string>
enum AssetType
{
	MESH
	// Other resources can go here,
	// such as audioClips, backgroundMusic, textures, shaders, etc
};

class Asset
{
public:

	Asset(int id, std::string name, AssetType type)
		: id(id), name(name), type(type) {};
	virtual ~Asset() {};

	int GetID() const { return id; }
	AssetType GetType() const { return type; }

private:

	int id;
	std::string name;
	AssetType type;
};