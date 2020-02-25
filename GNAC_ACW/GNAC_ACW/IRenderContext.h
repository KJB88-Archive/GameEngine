#pragma once

#ifdef DX_BUILD
#include <d3d11.h>
#else
#include <opengl.h>
#endif

class IRenderContext
{
public:
#ifdef DX_BUILD
	IRenderContext(ID3D11DeviceContext* context)
		: m_context(context) {};
#else
	IRenderContext(GLDeviceContext* context)
		: m_context(context) {};
#endif

	virtual ~IRenderContext() {};

#ifdef DX_BUILD
	ID3D11DeviceContext* GetContext()
	{
		return m_context;
	}
#else
	GL_RenderingDeviceContext* GetContext()
	{
		return m_context;
	}
#endif

private:

#ifdef DX_BUILD
	ID3D11DeviceContext* m_context;
#else
	GLDeviceContext* m_context;
#endif
};