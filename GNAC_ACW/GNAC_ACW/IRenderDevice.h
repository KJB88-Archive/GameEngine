#pragma once

#ifdef DX_BUILD
#include <d3d11.h>
#else
#include <opengl.h>
#endif

class IRenderDevice
{
public:

#ifdef DX_BUILD
	IRenderDevice(ID3D11Device* device)
		: m_device(device) {};
#else
	IRenderDevice(GLDevice* device)
		: m_device(device) {};
#endif

	~IRenderDevice() {};

#ifdef DX_BUILD
	ID3D11Device* GetDevice()
	{
		return m_device;
	}
#else
	GL_RenderingDevice* GetContext()
	{
		return m_device;
	}
#endif

private:

#ifdef DX_BUILD
	ID3D11Device* m_device;
#else
	GLDevice* m_device;
#endif
};