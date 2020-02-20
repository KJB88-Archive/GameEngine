#pragma once
#include "Asset.h"
#include "Vector3.h"
#include <vector>
#include "VBO.h"

class Mesh
	: public Asset
{
public:

	Mesh(int id, std::string name);
	virtual ~Mesh();

	// Getsets
	const int NumVerts();
	VBO* GetVBO() const;
	Vertex GetVertex(int i);
	Vertex& GetVertexRef(int i);

	// Vertex / VBO manip
	VBO* CreateVBO(Graphics* graphics);

	bool AddVertex(Vertex v);
	bool Clear();
	bool DeleteVertex(int i);

	bool Reset();

private:

	// VBO
	bool isLocked;
	VBO* vbo;

	// Mesh
	std::vector<Vertex> vertices;
	int indices[];
};