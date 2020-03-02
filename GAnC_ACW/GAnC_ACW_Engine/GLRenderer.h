#pragma once
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

#include <GL/GXBase/GXBase.h>

class GLRenderer
{
	GLRenderer(int, int, HWND, float, float);
	~GLRenderer();

	void BeginScene(float, float, float, float);
	void EndScene();

	void GetProjectionMatrix()
};
