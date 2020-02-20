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

	const int NoOfVerts();
	VBO* GetVBO() const;

	void AddVertex(Vertex v);
	void Clear();
	void DeleteVertex(int i);

private:

	bool m_locked;
	VBO* m_vbo;
	std::vector<Vertex> m_vertices;
	int indices[];
};