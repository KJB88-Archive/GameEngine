#pragma once
#include "Asset.h"
#include "Vector3.h"
#include <vector>
#include "VBO.h"

class Renderer;

class Mesh
	: public Asset
{
public:

	Mesh();
	virtual ~Mesh();

	// Getsets
	const int NumVerts();
	VBO* GetVBO() const;
	Vertex GetVertex(int i);
	Vertex& GetVertexRef(int i);
	int GetIndex(int i);

	// Vertex / VBO manip
	void CreateVBO(Renderer* renderer);

	bool AddVertex(Vertex v);
	bool AddIndex(int i);
	bool Clear();
	bool DeleteVertex(int i);
	bool DeleteIndex(int i);

	void Reset();

private:

	// VBO
	bool isLocked;
	VBO* vbo;

	// Mesh
	std::vector<Vertex> vertices;
	std::vector<int> indices;
};