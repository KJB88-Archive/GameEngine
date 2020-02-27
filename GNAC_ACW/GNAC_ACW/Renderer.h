#pragma once
#include "IRenderContext.h"
#include "IRenderDevice.h"
#include "Vertex.h"

#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"
#include <vector>

class VBO;
class Window;
class RenderSystem;

class Renderer
{
public:

	Renderer(int screenWidth, int screenHeight, Window* window, float screenDepth, float screenNear);
	virtual ~Renderer() {};

	virtual VBO* CreateVBO(std::vector<Vertex> vertices, int numVerts) = 0;
	virtual void BeginScene(float r, float g, float b, float a) = 0;
	virtual void Draw(VBO* vbo, int vCount) = 0;
	virtual void EndScene() = 0;

	virtual IRenderDevice* GetDevice() = 0;
	virtual IRenderContext* GetContext() = 0;
	virtual RenderSystem* GetSystem() = 0;

	//virtual void GetOrtho(glm::mat4& ortho) = 0;
	//virtual void GetProj(glm::mat4& proj) = 0;
	//virtual void GetWorld(glm::mat4& world) = 0;
	//virtual void GetView(glm::mat4& view) = 0;

protected:

	int m_screenWidth;
	int m_screenHeight;
	float m_screenNear;
	float m_screenFar;

	// Ref to Window allows for cross-platform (as Window could be cross-platform in future)
	Window* m_window; 

};