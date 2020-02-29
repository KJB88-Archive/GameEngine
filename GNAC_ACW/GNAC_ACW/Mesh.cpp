#include "Mesh.h"
#include "Vertex.h"
#include "Renderer.h"

#if DX_BUILD
#include "DX_VBO.h"
#endif
#if GL_BUILD
#include "GL_VBO.h"
#endif

Mesh::Mesh(int id, std::string name)
	: Asset(id, name, MESH)
{

}

Mesh::~Mesh()
{
	delete vbo;
	vbo = NULL;
}

VBO* Mesh::GetVBO() const
{
	return vbo;
}

void Mesh::CreateVBO(Renderer* renderer)
{
#if DX_BUILD
	vbo = new DX_VBO();
#endif
#if GL_BUILD
	vbo = new GL_VBO();
#endif

	vbo->Create(renderer, vertices, NumVerts());
}

const int Mesh::NumVerts()
{
	return (int)vertices.size();
}

Vertex Mesh::GetVertex(int i)
{
	return vertices[i];
}

Vertex& Mesh::GetVertexRef(int i)
{
	return vertices[i];
}

bool Mesh::AddVertex(Vertex v)
{
	if (!isLocked)
	{
		vertices.push_back(v);
		return true;
	}
	else
	{
		return false;
	}
}

bool Mesh::DeleteVertex(int i)
{
	if (isLocked)
	{
		vertices.erase(vertices.begin() + i);
		return true;
	}
	else
	{
		return false;
	}
}

bool Mesh::Clear()
{
	if (!isLocked)
	{
		vertices.clear();
		return true;
	}

	return false;
}

void Mesh::Reset()
{
	delete vbo;
	vbo = NULL;
	isLocked = false;
}