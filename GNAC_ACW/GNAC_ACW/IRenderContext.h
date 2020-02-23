#pragma once

#ifdef DX_BUILD
#include <d3d11.h>
#else
#include <opengl.h>
#endif

class IRenderContext
{
public:

	IRenderContext();
	virtual ~IRenderContext();

#ifdef DX_BUILD
	ID3D11Device* GetContext();
#else
	GL_RenderingDevice* GetContext();
#endif

private:

#ifdef DX_BUILD
	ID3D11DeviceContext* device;
#else
	GLDeviceContext device;
#endif
};