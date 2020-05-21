#include "DXShader.h"
#include "DXRenderer.h"
#include "Logger.h"

#include <string>

using namespace std;
using namespace DirectX;

DXShader::DXShader(DXRenderer* renderer)
	: m_vShader(nullptr), m_pShader(nullptr), m_layout(nullptr), m_cbWVP(nullptr)
{
	HRESULT result;
	ID3DBlob* error;

	ID3DBlob *VS;
	result = D3DX11CompileFromFile("PassthroughVertex.hlsl", 0, 0, "VShader", "vs_4_0_level_9_3", 0, 0, 0, &VS, &error, 0);
	if (FAILED(result))
	{
		printf("DXSHADER: Unable to compile VS from file.\n");
	}

	ID3DBlob *PS;
	result = D3DX11CompileFromFile("ColorPixel.hlsl", 0, 0, "PShader", "ps_4_0_level_9_3", 0, 0, 0, &PS, &error, 0);
	if (FAILED(result))
	{
		printf("DXSHADER: Unable to compile PS from file.\n");
	}

	result = renderer->GetDevice()->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), NULL, &m_vShader);
	if (FAILED(result))
	{
		// DEBUG
		printf("DXSHADER: Unable to create Vertex Shader.\n");
	}

	result = renderer->GetDevice()->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &m_pShader);
	if (FAILED(result))
	{
		// DEBUG
		printf("DXSHADER: Unable to create Pixel Shader.\n");
	}

	// Set shaders (do not change for now) TODO
	renderer->GetContext()->VSSetShader(m_vShader, NULL, 0);
	renderer->GetContext()->PSSetShader(m_pShader, NULL, 0);

	// Vertex Input Layout
	D3D11_INPUT_ELEMENT_DESC polygonLayout[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};
	unsigned int numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	result = renderer->GetDevice()->CreateInputLayout(polygonLayout, numElements, VS->GetBufferPointer(), VS->GetBufferSize(), &m_layout);
	if (FAILED(result))
	{
		// DEBUG
		Logger::LogToConsole("SHADER: Failed to create Input Layout.");
	}

	// Assign IL (does not change for now) TODO
	renderer->GetContext()->IASetInputLayout(m_layout);

	VS->Release();
	VS = nullptr;
	PS->Release();
	PS = nullptr;

	// Constant Buffer
	D3D11_BUFFER_DESC matrixBufferDesc;
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBuffer);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	result = renderer->GetDevice()->CreateBuffer(&matrixBufferDesc, NULL, &m_cbWVP);
	if (FAILED(result))
	{
		// Debug
		Logger::LogToConsole("SHADER: Failed to create constant buffer.");
	}
}

DXShader::~DXShader()
{
	if (m_cbWVP)
	{
		m_cbWVP->Release();
		m_cbWVP = nullptr;
	}

	if (m_layout)
	{
		m_layout->Release();
		m_layout = nullptr;
	}

	if (m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}

	if (m_vShader)
	{
		m_vShader->Release();
		m_vShader = nullptr;
	}
}

void DXShader::SetShaderParameters(ID3D11DeviceContext* context, XMMATRIX& world, XMMATRIX& view, XMMATRIX& proj)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBuffer* dataPtr;
	unsigned int bufferNo;

	// Make a copy of the refs (hacky fix)
	XMMATRIX nWorld = world;
	XMMATRIX nView = view;
	XMMATRIX nProj = proj;

	nWorld = XMMatrixTranspose(nWorld);
	nView = XMMatrixTranspose(nView);
	nProj = XMMatrixTranspose(nProj);

	context->Map(m_cbWVP, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	dataPtr = (MatrixBuffer*)mappedResource.pData;
	dataPtr->world = nWorld;
	dataPtr->view = nView;
	dataPtr->proj = nProj;
	context->Unmap(m_cbWVP, 0);

	bufferNo = 0;
	context->VSSetConstantBuffers(bufferNo, 1, &m_cbWVP);
}

void DXShader::Render(ID3D11DeviceContext* context, int iCount, XMMATRIX& world, XMMATRIX& view, XMMATRIX& proj)
{
	SetShaderParameters(context, world, view, proj);
	RenderShader(context, iCount);
}

void DXShader::RenderShader(ID3D11DeviceContext* context, int iCount)
{
	context->DrawIndexed(iCount, 0, 0);
}