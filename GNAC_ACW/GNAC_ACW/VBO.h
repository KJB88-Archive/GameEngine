#pragma once
#include "Vertex.h"

class Graphics;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create(Graphics* gm, Vertex vertices[], int noOfVerts) = 0;
	virtual void Draw(Graphics* gm) = 0;

protected:

	int m_noOfVerts;
	int m_noOfIndices;
};