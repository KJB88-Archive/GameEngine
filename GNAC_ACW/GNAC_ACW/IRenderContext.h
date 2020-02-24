#pragma once

#ifdef DX_BUILD
#include <d3d11.h>
#else
#include <opengl.h>
#endif

class IRenderContext
{
public:

	IRenderContext() {};
	virtual ~IRenderContext() {};

#ifdef DX_BUILD
	ID3D11DeviceContext* GetContext()
	{
		return context;
	}
#else
	GL_RenderingDeviceContext* GetContext()
	{
		return context;
	}
#endif

private:

#ifdef DX_BUILD
	ID3D11DeviceContext* context;
#else
	GLDeviceContext context;
#endif
};