#pragma once
#include "Vertex.h"
#include <vector>
class IRenderDevice;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create(IRenderDevice* device, std::vector<Vertex> vertices, int noOfVerts) = 0;

protected:

	int m_noOfVerts;
	int m_noOfIndices;
};