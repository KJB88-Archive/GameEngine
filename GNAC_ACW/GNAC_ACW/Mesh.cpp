#include "Mesh.h"
#include "Vertex.h"
#include "VBO.h"

Mesh::Mesh(int id, std::string name)
	: Asset(id, name, MESH)
{

}

Mesh::~Mesh()
{

}

const int Mesh::NoOfVerts()
{
	return (int)m_vertices.size();
}

void Mesh::AddVertex(VertexStruct v)
{
	if (!m_locked)
	{
		m_vertices.push_back(v);
		return;
	}
}