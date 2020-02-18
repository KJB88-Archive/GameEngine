#pragma once
#include "Vertex.h"
#define DX_BUILD = 1;

//#ifdef DX_BUILD
//#include "DX_VBO.h"
//#else
//#include "GL_VBO.h"
//#endif

class Graphics;

class VBO
{
public:

	VBO() {};
	virtual ~VBO() {};

	virtual void Create(Graphics* graphics, Vertex vertices[], int noOfVerts) = 0;
	virtual void Draw(Graphics* graphics) = 0;

protected:

//#ifdef DX_BUILD
//	DX_VBO* vbo;
//#else
//	GL_VBO* vbo;
//#endif

	int m_noOfVerts;
	int m_noOfIndices;
};