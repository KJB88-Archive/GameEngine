#include "Mesh.h"
#include "Vertex.h"
#include "VBO.h"
#include "Graphics.h"

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

VBO* Mesh::CreateVBO(Graphics* graphics)
{
	isLocked = true;

	graphics->GetRenderer()->CreateVBO(vertices, numVerts);

	//vbo->Create(graphics, vertices, numVerts);
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

bool Mesh::Reset()
{
	delete vbo;
	vbo = NULL;
	isLocked = false;
}