#pragma once
#include <vector>
#include <string>

#include "Mesh.h"
#include "Graphics.h"
#include "Asset.h"

// TODO - Replace Mesh with Asset
class Resources
	: public Manager
{

public:

	Resources();
	virtual ~Resources();

	Mesh* CreateMesh(std::string fileName);
	bool GetMesh(std::string assetName, Mesh& outMesh);
	bool GetMesh(const int id, Mesh& outMesh);

private:

	std::vector<Mesh*> assets;
};