#pragma once
#include "IRenderContext.h"
#include "IRenderDevice.h"
#include "Vertex.h"

#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"

class VBO;
class Window;
class RenderSystem;

class IRenderer
{
public:

	IRenderer(int screenWidth, int screenHeight, Window* window, float screenNear, float screenFar);
	virtual ~IRenderer();

	virtual VBO* CreateVBO(Vertex vertices[], int numVerts) = 0;
	virtual void BeginScene(float r, float g, float b, float a) = 0;
	virtual void EndScene() = 0;

	virtual IRenderDevice* GetDevice() = 0;
	virtual IRenderContext* GetContext() = 0;
	virtual RenderSystem* GetSystem() = 0;

	virtual glm::mat4 GetOrtho(glm::mat4& ortho) = 0;
	virtual glm::mat4 GetProj(glm::mat4& proj) = 0;
	virtual glm::mat4 GetWorld(glm::mat4& world) = 0;
	virtual glm::mat4 GetView(glm::mat4& view) = 0;

protected:

	int m_screenWidth;
	int m_screenHeight;
	Window* m_window;
	float m_screenNear;
	float m_screenFar;
};