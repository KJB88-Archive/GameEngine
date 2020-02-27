#pragma once
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <d3d11.h>
#include <DirectXMath.h>

#include "DX_VBO.h"
#include "Renderer.h"

class Window;

class DXRenderer
	: public Renderer
{
public:

	DXRenderer(int screenWidth, int screenHeight, Window* window, float screenDepth, float screenNear);
	virtual ~DXRenderer();

	// Core D3D Gets
	virtual IRenderDevice* GetDevice() override { return iDevice; }
	virtual IRenderContext* GetContext() override { return iContext; }

	virtual RenderSystem * GetSystem() override;

	// VBO Creation
	virtual VBO* CreateVBO(std::vector<Vertex> vertices, int numVerts) override;

	// Scene rendering
	virtual void BeginScene(float r, float g, float b, float a) override;
	virtual void Draw(VBO* vbo, int vCount) override;
	virtual void EndScene() override;


	// Matrices
	//virtual void GetOrtho(glm::mat4& ortho) override;
	//virtual void GetProj(glm::mat4& proj)override;
	//virtual void GetWorld(glm::mat4& world) override;
	//virtual void GetView(glm::mat4& view) override;

private:

	// Initialize DX Resources
	void InitializeCoreD3D(int screenWidth, int screenHeight, HWND hwnd);
	void InitializeSecondaryD3D(int screenWidth, int screenHeight);
	void InitializeMatricesD3D(int screenWidth, int screenHeight, float screenDepth, float screenNear);

	// Rendering Abstractions
	void InitializeRenderSystem();
	void CreateAbstractDevice();
	void CreateAbstractContext();

	// Core DX Resources
	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;

	// Matrices
	DirectX::XMMATRIX projection;
	DirectX::XMMATRIX world;
	DirectX::XMMATRIX orthographic;

	// Abstract
	IRenderDevice* iDevice;
	IRenderContext* iContext;

	// Systems
	RenderSystem* renderSystem;

	//void GetProjectionMatrix(DirectX::XMMATRIX&);
	//void GetWorldMatrix(DirectX::XMMATRIX&);
	//void GetOrthographicMatrix(DirectX::XMMATRIX&);

	// Prevent copy and assignment
	DXRenderer(const DXRenderer&) = delete;
	DXRenderer* operator=(const DXRenderer&) = delete;
};