#pragma once
#include "Vertex.h"

class Graphics;
class IRenderDevice;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create(IRenderDevice* device, Vertex vertices[], int noOfVerts) = 0;
	virtual void Draw(IRenderDevice* device) = 0;

protected:

	int m_noOfVerts;
	int m_noOfIndices;
};