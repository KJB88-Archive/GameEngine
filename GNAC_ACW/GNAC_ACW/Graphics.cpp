//#include "Graphics.h"
//
//#include "RenderSystem.h"
//
//Graphics* Graphics::instance = NULL;
//
//Graphics::Graphics(int screenWidth, int screenHeight, HWND hWnd)
//	: Manager("Graphics"), m_renderer(nullptr), m_shader(nullptr), m_camera(nullptr)
//{
//	instance = this;
//#ifdef DX_BUILD 
//	m_renderer = new DXRenderer(screenWidth, screenHeight, hWnd, SCREEN_DEPTH, SCREEN_NEAR);
//	m_camera = new DXCamera();
//	m_camera->SetPosition(0.0f, 0.0f, -5.0f);
//	m_shader = new DXShader(m_renderer->GetDevice());
//
//#else
//	m_renderer = new GLRenderer(screenWidth, screenHeight, hWnd, SCREEN_DEPTH, SCREEN_NEAR);
//#endif
//
//
//}
//
//Graphics::~Graphics()
//{
//	if (m_shader)
//	{
//		delete m_shader;
//		m_shader = nullptr;
//	}
//
//	if (m_camera)
//	{
//		delete m_camera;
//		m_camera = nullptr;
//	}
//
//	if (m_renderer)
//	{
//		delete m_renderer;
//		m_renderer = nullptr;
//	}
//}
//
//IRenderer* Graphics::GetRenderer()
//{
//	return m_renderer;
//}
//
//
//RenderSystem* Graphics::GetSystem()
//{
//	if (renderSystem == NULL)
//	{
//		renderSystem = new RenderSystem(this);
//	}
//
//	return renderSystem;
//}
//
//VBO* Graphics::CreateVBO(Vertex vertices[], int numVerts)
//{
//	VBO* vbo;
//	vbo = m_renderer->CreateVBO(vertices, numVerts);
//	return vbo;
//}
//
//void Graphics::BeginScene()
//{
//	m_renderer->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
//
//	m_camera->Render();
//
//	m_renderer->GetWorldMatrix(world);
//	m_camera->GetViewMatrix(view);
//	m_renderer->GetProjectionMatrix(proj);
//}
////
////void Graphics::Draw(Mesh* mesh)
////{
////	mesh->Render(m_renderer->GetContext());
////}
//
//void Graphics::EndScene()
//{
//	m_shader->Render(m_renderer->GetContext(), m_mesh->GetIndexCount(), world, view, proj);
//	m_renderer->EndScene();
//}