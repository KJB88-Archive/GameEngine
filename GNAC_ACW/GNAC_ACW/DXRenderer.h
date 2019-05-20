#pragma once
#pragma comment(lib, "d3d11.lib");
#pragma comment(lib, "dxgi.lib");
#pragma comment(lib, "d3dcompiler.lib");

#include <d3d11.h>
#include <DirectXMath.h>

class DXRenderer
{
public:

	DXRenderer(int, int, HWND, float, float);
	~DXRenderer();

	void BeginScene(float, float, float, float);
	void EndScene();

	ID3D11Device* GetDevice() { return m_device; }
	ID3D11DeviceContext* GetContext() { return m_context; }

	void GetProjectionMatrix(DirectX::XMMATRIX&);
	void GetWorldMatrix(DirectX::XMMATRIX&);
	void GetOrthographicMatrix(DirectX::XMMATRIX&);

private:

	void InitializeCoreD3D(int, int, HWND);
	void InitializeSecondaryD3D(int, int);
	void InitializeMatricesD3D(int, int, float, float);

	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;

	DirectX::XMMATRIX m_proj;
	DirectX::XMMATRIX m_world;
	DirectX::XMMATRIX m_ortho;

	DXRenderer(const DXRenderer&) = delete;
	DXRenderer* operator=(const DXRenderer&) = delete;
};