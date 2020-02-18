#pragma once
#include "Asset.h"
#include <vector>

class VBO;
class Vertex;

class Mesh
	: public Asset
{
public:
	Mesh(int id, std::string name);
	virtual ~Mesh();

	const int NoOfVerts();
	//VBO* GetVBO() const;

	//VBO* CreateVBO(GraphicsManager* gm);
	void AddVertex(Vertex v);
	void Clear();
	void DeleteVertex(int i);

private:

	bool m_locked;
	//VBO* m_vbo;
	std::vector<Vertex> m_vertices;
	int indices[];
};