#include "Graphics.h"

#include "RenderSystem.h"

Graphics* Graphics::instance = nullptr;

Graphics::Graphics(int screenWidth, int screenHeight, HWND hWnd)
	: Manager("Graphics"), m_renderer(nullptr), m_mesh(nullptr), m_shader(nullptr), m_camera(nullptr)
{
	instance = this;

#ifdef DX_BUILD 
	m_renderer = new DXRenderer(screenWidth, screenHeight, hWnd, SCREEN_DEPTH, SCREEN_NEAR);
	m_camera = new DXCamera();
	m_camera->SetPosition(0.0f, 0.0f, -5.0f);
	m_shader = new DXShader(m_renderer->GetDevice());
	m_mesh = new DXMesh(m_renderer->GetDevice());

#else
	m_renderer = new GLRenderer(screenWidth, screenHeight, hWnd, SCREEN_DEPTH, SCREEN_NEAR);
#endif
}

Graphics::~Graphics()
{
	if (m_shader)
	{
		delete m_shader;
		m_shader = nullptr;
	}

	if (m_mesh)
	{
		delete m_mesh;
		m_mesh = nullptr;
	}

	if (m_camera)
	{
		delete m_camera;
		m_camera = nullptr;
	}

	if (m_renderer)
	{
		delete m_renderer;
		m_renderer = nullptr;
	}
}

#ifdef DX_BUILD
DXRenderer* Graphics::GetRenderer()
{
	return m_renderer;
}
#else
GLRenderer* GraphicsManager::GetRenderer()
{
	return m_renderer;
}
#endif

//bool GraphicsManager::OnFrame()
//{
//	bool result = Render();
//	if (!result)
//	{
//		return false;
//	}
//
//	return true;
//}

RenderSystem* Graphics::GetSystem()
{

}

void Graphics::BeginScene()
{
	m_renderer->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	m_camera->Render();

	m_renderer->GetWorldMatrix(world);
	m_camera->GetViewMatrix(view);
	m_renderer->GetProjectionMatrix(proj);
}

void Graphics::Draw(DXMesh* mesh)
{
	mesh->Render(m_renderer->GetContext());
}

void Graphics::EndScene()
{
	m_shader->Render(m_renderer->GetContext(), m_mesh->GetIndexCount(), world, view, proj);
	m_renderer->EndScene();
}

//bool GraphicsManager::Render()
//{
//	DirectX::XMMATRIX world, view, proj;
//	m_renderer->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
//
//	m_camera->Render();
//
//	m_renderer->GetWorldMatrix(world);
//	m_camera->GetViewMatrix(view);
//	m_renderer->GetProjectionMatrix(proj);
//
//	m_mesh->Render(m_renderer->GetContext());
//
//	m_shader->Render(m_renderer->GetContext(), m_mesh->GetIndexCount(), world, view, proj);
//	m_renderer->EndScene();
//
//	return true;
//}