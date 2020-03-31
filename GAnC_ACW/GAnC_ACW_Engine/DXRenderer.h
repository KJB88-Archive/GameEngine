#pragma once
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <d3d11.h>
#include <DirectXMath.h>

#include "DX_VBO.h"
#include "Renderer.h"
#include "DXShader.h"
#include "DXCamera.h"

class Window;

class DXRenderer
	: public Renderer
{
public:
	DXRenderer(int screenWidth, int screenHeight, HWND hwnd, float screenDepth, float screenNear);
	virtual ~DXRenderer();

	ID3D11Device* GetDevice() const;
	ID3D11DeviceContext* GetContext() const;

	virtual RenderSystem * GetSystem() override;

	//static DXCamera* CreateCamera();
	//static DX_VBO* CreateVBO();

	// Scene rendering
	virtual void BeginScene(float r, float g, float b, float a) override;
	virtual void Draw(const Vector3& pos, const Vector3& rot, const Vector3& scale, const Mesh* mesh) override;
	virtual void EndScene() override;

	// Matrices
	void GetProjectionMatrix(DirectX::XMMATRIX& proj);
	void GetWorldMatrix(DirectX::XMMATRIX& world);
	void GetOrthographicMatrix(DirectX::XMMATRIX& ortho);
	void GetViewMatrix(DirectX::XMMATRIX& view);

private:

	// Initialize DX Resources
	void InitializeCoreD3D(int screenWidth, int screenHeight, HWND hwnd);
	void InitializeSecondaryD3D(int screenWidth, int screenHeight);

	// Rendering Abstractions
	void InitializeRenderSystem();

	// Core DX Resources
	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;

	DXShader* m_shader;
	DXCamera* m_camera;
	//std::vector<DXCamera*> m_cams;

	// Matrices
	DirectX::XMMATRIX m_projection;
	DirectX::XMMATRIX m_world;
	DirectX::XMMATRIX m_ortho;
	DirectX::XMMATRIX m_view;

	// Systems
	RenderSystem* renderSystem;

	// Prevent copy and assignment
	DXRenderer(const DXRenderer&) = delete;
	DXRenderer* operator=(const DXRenderer&) = delete;
};