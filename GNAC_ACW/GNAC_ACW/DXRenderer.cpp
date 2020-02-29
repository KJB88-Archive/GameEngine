#include "DXRenderer.h"
#include "stdio.h"

#include "DX_VBO.h"
#include "RenderSystem.h"

using namespace DirectX;

struct DXVertex
{
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT4 color;
};

void DXRenderer::TestDraw()
{
	printf("RENDERER: " + m_id);
	//DXVertex* dxVerts;
	////unsigned long* indices;
	//D3D11_BUFFER_DESC vBufferDesc/*, iBufferDesc*/;
	//D3D11_SUBRESOURCE_DATA vData/*, iData*/;
	//HRESULT result;

	//// Convert from generic struct to DX specific struct
	//// TODO 

	//int m_vCount = 4;
	////m_iCount = 6;

	//dxVerts = new DXVertex[m_vCount];
	////indices = new unsigned long[m_iCount];

	//dxVerts[0].position = XMFLOAT3(1.0f, 1.0f, 0.0f);
	//dxVerts[1].position = XMFLOAT3(-1.0f, 1.0f, 0.0f);
	//dxVerts[2].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);
	//dxVerts[3].position = XMFLOAT3(1.0f, -1.0f, 0.0f);

	////vertices[4].position = XMFLOAT3(0.0f, 0.0f, 1.0f);
	////vertices[5].position = XMFLOAT3(1.0f, 0.0f, 1.0f);
	////vertices[6].position = XMFLOAT3(1.0f, 1.0f, 1.0f);
	////vertices[7].position = XMFLOAT3(0.0f, 1.0f, 1.0f);

	//for (int i = 0; i < m_vCount; ++i)
	//{
	//	dxVerts[i].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	//}

	////indices[0] = 0;
	////indices[1] = 3;
	////indices[2] = 2;
	////indices[3] = 2;
	////indices[4] = 1;
	////indices[5] = 0;


	//vBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	//vBufferDesc.ByteWidth = sizeof(DXVertex) * m_vCount;
	//vBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	//vBufferDesc.CPUAccessFlags = 0;
	//vBufferDesc.MiscFlags = 0;
	//vBufferDesc.StructureByteStride = 0;

	//// Give subresource data
	//vData.pSysMem = dxVerts;
	//vData.SysMemPitch = 0;
	//vData.SysMemSlicePitch = 0;

	//ID3D11Buffer* m_vBuffer;
	//GetDevice()->CreateBuffer(&vBufferDesc, &vData, &m_vBuffer);

	//// select which vertex buffer to display
	//UINT stride = sizeof(DXVertex);
	//UINT offset = 0;

	//GetContext()->IASetVertexBuffers(0, 1, &m_vBuffer, &stride, &offset);

	//// select which primtive type we are using
	//GetContext()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP);

	//// draw the vertex buffer to the back buffer
	//GetContext()->Draw(m_vCount, 0);

}

DXRenderer::DXRenderer(int screenWidth, int screenHeight, HWND hWnd, float screenDepth, float screenNear)
	: Renderer(screenWidth, screenHeight, screenDepth, screenNear)
{
	InitializeCoreD3D(screenWidth, screenHeight, hWnd);
	InitializeSecondaryD3D(screenWidth, screenHeight);
	InitializeMatricesD3D(screenWidth, screenHeight, screenDepth, screenNear);
	InitializeRenderSystem();

	m_id = 9999;
}

DXRenderer::~DXRenderer()
{
	if (m_swapChain)
	{
		m_swapChain->SetFullscreenState(false, NULL);
	}

	if (m_rasterState)
	{
		m_rasterState->Release();
		m_rasterState = nullptr;
	}

	if (m_depthStencilView)
	{
		m_depthStencilView->Release();
		m_depthStencilView = nullptr;
	}

	if (m_depthStencilState)
	{
		m_depthStencilState->Release();
		m_depthStencilState = nullptr;
	}

	if (m_depthStencilBuffer)
	{
		m_depthStencilBuffer->Release();
		m_depthStencilBuffer = nullptr;
	}

	if (m_renderTargetView)
	{
		m_renderTargetView->Release();
		m_renderTargetView = nullptr;
	}

	if (m_context)
	{
		m_context->Release();
		m_context = nullptr;
	}

	if (m_device)
	{
		m_device->Release();
		m_device = nullptr;
	}

	if (m_swapChain)
	{
		m_swapChain->Release();
		m_swapChain = nullptr;
	}
}

ID3D11Device* DXRenderer::GetDevice() const
{
	return m_device;
}

ID3D11DeviceContext* DXRenderer::GetContext() const
{
	return m_context;
}

void DXRenderer::InitializeCoreD3D(int screenWidth, int screenHeight, HWND hwnd)
{
	HRESULT result;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Texture2D* backBufferPtr;

	// Init. SC descriptor
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = screenWidth;
	swapChainDesc.BufferDesc.Height = screenHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	swapChainDesc.OutputWindow = hwnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = true;

	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = 0;

	featureLevel = D3D_FEATURE_LEVEL_11_0;

	UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;

	// Create Device, DeviceContext and SwapChain
	result = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, creationFlags, &featureLevel, 1, D3D11_SDK_VERSION,
		&swapChainDesc, &m_swapChain, &m_device, NULL, &m_context);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to create graphics device, swap chain or graphics context.\n");
	}

	// Setup back buffer
	result = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferPtr);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to get back buffer.\n");
	}

	// Create Render Target View
	result = m_device->CreateRenderTargetView(backBufferPtr, NULL, &m_renderTargetView);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to create render target view.\n");
	}

	backBufferPtr->Release();
	backBufferPtr = nullptr;
}

void DXRenderer::InitializeSecondaryD3D(int screenWidth, int screenHeight)
{
	HRESULT result;
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
	D3D11_VIEWPORT viewport;

	// Init. depth buffer
	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

	depthBufferDesc.Width = screenWidth;
	depthBufferDesc.Height = screenHeight;
	depthBufferDesc.MipLevels = 1;
	depthBufferDesc.ArraySize = 1;
	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthBufferDesc.SampleDesc.Count = 1;
	depthBufferDesc.SampleDesc.Quality = 0;
	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthBufferDesc.CPUAccessFlags = 0;
	depthBufferDesc.MiscFlags = 0;

	result = m_device->CreateTexture2D(&depthBufferDesc, NULL, &m_depthStencilBuffer);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to create depth stencil buffer.\n");
	}

	// Init. Stencil State
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

	depthStencilDesc.DepthEnable = true;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;

	// Stencil ops for front-facing
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Stencil ops for back-facing
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	result = m_device->CreateDepthStencilState(&depthStencilDesc, &m_depthStencilState);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to create depth stencil state.\n");
	}

	m_context->OMSetDepthStencilState(m_depthStencilState, 1);

	// Init. Depth Stencil View
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	result = m_device->CreateDepthStencilView(m_depthStencilBuffer, &depthStencilViewDesc, &m_depthStencilView);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to create depth stencil view.\n");
	}

	// Bind RTV and DSB to render pipeline
	m_context->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);

	// Init Rasterizer
	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_NONE;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FrontCounterClockwise = false;
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

	result = m_device->CreateRasterizerState(&rasterDesc, &m_rasterState);
	if (FAILED(result))
	{
		printf("DIRECTX: Failed to create rasterizer state.\n");
	}

	m_context->RSSetState(m_rasterState);

	// Init. viewport
	viewport.Width = (float)screenWidth;
	viewport.Height = (float)screenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

	m_context->RSSetViewports(1, &viewport);

}

void DXRenderer::InitializeMatricesD3D(int screenWidth, int screenHeight, float screenDepth, float screenNear)
{
	float FoV, aspectRatio;

	// Proj
	FoV = XM_PIDIV4;
	aspectRatio = (float)screenWidth / (float)screenHeight;

	projection = XMMatrixPerspectiveFovLH(FoV, aspectRatio, screenNear, screenDepth);

	// World
	world = XMMatrixIdentity();

	// Ortho
	orthographic = XMMatrixOrthographicLH((float)screenWidth, (float)screenHeight, screenNear, screenDepth);
}

void DXRenderer::InitializeRenderSystem()
{
	renderSystem = new RenderSystem(this);
}


RenderSystem* DXRenderer::GetSystem()
{
	return renderSystem;
}

void DXRenderer::Draw(const Mesh* mesh)
{
	DX_VBO* vbo = (DX_VBO*)mesh->GetVBO();

	vbo->Draw(this);
}

void DXRenderer::BeginScene(float r, float g, float b, float a)
{
	float color[4];

	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;

	m_context->ClearRenderTargetView(m_renderTargetView, color);
	m_context->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DXRenderer::EndScene()
{
	m_swapChain->Present(0, 0);
}