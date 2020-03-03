#pragma once
#include "Mesh.h"
#include "Vertex.h"
#include "Colour.h"

#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"
#include <vector>

class VBO;
class RenderSystem;

class Renderer
{
public:

	Renderer(int screenWidth, int screenHeight, float screenDepth, float screenNear) {};
	virtual ~Renderer() {};

	virtual void BeginScene(float r, float g, float b, float a) = 0;
	virtual void Draw(const Mesh* mesh) = 0;
	virtual void EndScene() = 0;

	virtual RenderSystem* GetSystem() = 0;

protected:

	int m_screenWidth;
	int m_screenHeight;
	float m_screenNear;
	float m_screenFar;
};