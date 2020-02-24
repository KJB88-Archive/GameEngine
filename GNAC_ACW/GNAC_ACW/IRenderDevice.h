#pragma once

#ifdef DX_BUILD
#include <d3d11.h>
#else
#include <opengl.h>
#endif

class IRenderDevice
{
public:

	IRenderDevice() {};
	virtual ~IRenderDevice() {};

#ifdef DX_BUILD
	ID3D11Device* GetDevice()
	{
		return device;
	}
#else
	GL_RenderingDevice* GetContext()
	{
		return device;
	}
#endif

private:

#ifdef DX_BUILD
	ID3D11Device* device;
#else
	GLDeviceContext context;
#endif
};