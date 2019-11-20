#include "Mesh.h"
#include "Vertex.h"

Mesh::Mesh(int id, std::string name)
	: Resource(id, name, MESH)
{

}

Mesh::~Mesh()
{

}

const int Mesh::NoOfVerts()
{
	return (int)m_vertices.size();
}

void Mesh::AddVertex(Vertex v)
{
	if (!m_locked)
	{
		m_vertices.push_back(v);
		return;
	}
}