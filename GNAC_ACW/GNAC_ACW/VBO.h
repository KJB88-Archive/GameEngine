#pragma once
#include "Vertex.h"

class Graphics;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create(Graphics* graphics, Vertex vertices[], int noOfVerts) = 0;
	virtual void Draw(Graphics* graphics) = 0;

protected:

	int m_noOfVerts;
	int m_noOfIndices;
};