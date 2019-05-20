#pragma once
#include "Vertex.h"

class GraphicsManager;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create(GraphicsManager* gm, Vertex vertices[], int noOfVerts) = 0;
	virtual void Draw(GraphicsManager* gm) = 0;

protected:

	int m_noOfVerts;
	int m_noOfIndices;
};