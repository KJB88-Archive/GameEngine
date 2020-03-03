#include "DXShader.h"
#include "DXRenderer.h"

#include <string>

using namespace std;
using namespace DirectX;

DXShader::DXShader(DXRenderer* renderer)
	: m_vShader(nullptr), m_pShader(nullptr), m_layout(nullptr), m_matrixBuffer(nullptr)
{
	HRESULT result;
	ID3D10Blob *VS, *PS;
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;

	D3DX11CompileFromFile("PassthroughVertex.hlsl", 0, 0, "VShader", "vs_4_0_level_9_3", 0, 0, 0, &VS, 0, 0);
	D3DX11CompileFromFile("ColorPixel.hlsl", 0, 0, "PShader", "ps_4_0_level_9_3", 0, 0, 0, &PS, 0, 0);

	result = renderer->GetDevice()->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), NULL, &m_vShader);
	if (FAILED(result))
	{
		// DEBUG
	}
	result = renderer->GetDevice()->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &m_pShader);
	if (FAILED(result))
	{
		// DEBUG
	}

	renderer->GetContext()->VSSetShader(m_vShader, NULL, 0);
	renderer->GetContext()->PSSetShader(m_pShader, NULL, 0);

	// Vertex Input Layout
	D3D11_INPUT_ELEMENT_DESC polygonLayout[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	result = renderer->GetDevice()->CreateInputLayout(polygonLayout, numElements, VS->GetBufferPointer(), VS->GetBufferSize(), &m_layout);
	if (FAILED(result))
	{
		// DEBUG
	}

	renderer->GetContext()->IASetInputLayout(m_layout);

	VS->Release();
	VS = nullptr;
	PS->Release();
	PS = nullptr;

	// Constant Buffer
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBuffer);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	result = renderer->GetDevice()->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
	if (FAILED(result))
	{
		// Debug
	}
	XMMATRIX world;
	renderer->GetWorldMatrix(world);
	XMMATRIX proj;
	renderer->GetProjectionMatrix(proj);
	XMMATRIX ortho;
	renderer->GetOrthographicMatrix(ortho);
	XMMATRIX view;
	renderer->GetViewMatrix(view);

	SetShaderParameters(renderer->GetContext(), world, view, ortho);
}

DXShader::~DXShader()
{
	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = nullptr;
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

void DXShader::SetShaderParameters(ID3D11DeviceContext* context, XMMATRIX world, XMMATRIX view, XMMATRIX proj)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBuffer* dataPtr;
	unsigned int bufferNo;

	world = XMMatrixTranspose(world);
	view = XMMatrixTranspose(view);
	proj = XMMatrixTranspose(proj);

	context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	dataPtr = (MatrixBuffer*)mappedResource.pData;
	dataPtr->world = world;
	dataPtr->view = view;
	dataPtr->proj = proj;
	context->Unmap(m_matrixBuffer, 0);

	bufferNo = 0;
	context->VSSetConstantBuffers(bufferNo, 1, &m_matrixBuffer);
}

//void DXShader::Render(ID3D11DeviceContext* context, int iCount, XMMATRIX world, XMMATRIX view, XMMATRIX proj)
//{
//	SetShaderParameters(context, world, view, proj);
//	RenderShader(context, iCount);
//}
//
//void DXShader::RenderShader(ID3D11DeviceContext* context, int iCount)
//{
//	context->IASetInputLayout(m_layout);
//
//	context->VSSetShader(m_vShader, NULL, 0);
//	context->PSSetShader(m_pShader, NULL, 0);
//
//	context->DrawIndexed(iCount, 0, 0);
//}