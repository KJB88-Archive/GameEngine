#pragma once
#include "Vertex.h"
#include <vector>
class Renderer;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create
	(Renderer* renderer, std::vector<Vertex> vertices, int noOfVerts) = 0;

	virtual void Draw(Renderer* renderer) = 0;

protected:

	int m_noOfVerts;
	int m_noOfIndices;
};