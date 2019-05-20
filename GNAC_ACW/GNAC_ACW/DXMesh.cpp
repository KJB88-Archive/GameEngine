#include "DXMesh.h"

using namespace DirectX;

DXMesh::DXMesh(ID3D11Device* device)
	: m_vBuffer(nullptr), m_iBuffer(nullptr), m_vCount(0), m_iCount(0)
{
	InitializeBuffers(device);
}

DXMesh::~DXMesh()
{
	if (m_iBuffer)
	{
		m_iBuffer->Release();
		m_iBuffer = nullptr;
	}

	if (m_vBuffer)
	{
		m_vBuffer->Release();
		m_vBuffer = nullptr;
	}
}

void DXMesh::InitializeBuffers(ID3D11Device* device)
{
	Vertex* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vBufferDesc, iBufferDesc;
	D3D11_SUBRESOURCE_DATA vData, iData;
	HRESULT result;

	m_vCount = 4;
	m_iCount = 6;

	vertices = new Vertex[m_vCount];
	indices = new unsigned long[m_iCount];

	vertices[0].position = XMFLOAT3(1.0f, 1.0f, 0.0f);
	vertices[1].position = XMFLOAT3(-1.0f, 1.0f, 0.0f);
	vertices[2].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);
	vertices[3].position = XMFLOAT3(1.0f, -1.0f, 0.0f);

	//vertices[4].position = XMFLOAT3(0.0f, 0.0f, 1.0f);
	//vertices[5].position = XMFLOAT3(1.0f, 0.0f, 1.0f);
	//vertices[6].position = XMFLOAT3(1.0f, 1.0f, 1.0f);
	//vertices[7].position = XMFLOAT3(0.0f, 1.0f, 1.0f);

	for (int i = 0; i < m_vCount; ++i)
	{
		vertices[i].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	indices[0] = 0;
	indices[1] = 3;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 1;
	indices[5] = 0;


	vBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vBufferDesc.ByteWidth = sizeof(Vertex) * m_vCount;
	vBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vBufferDesc.CPUAccessFlags = 0;
	vBufferDesc.MiscFlags = 0;
	vBufferDesc.StructureByteStride = 0;

	// Give subresource data
	vData.pSysMem = vertices;
	vData.SysMemPitch = 0;
	vData.SysMemSlicePitch = 0;

	device->CreateBuffer(&vBufferDesc, &vData, &m_vBuffer);

	iBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	iBufferDesc.ByteWidth = sizeof(unsigned long) * m_iCount;
	iBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	iBufferDesc.CPUAccessFlags = 0;
	iBufferDesc.MiscFlags = 0;
	iBufferDesc.StructureByteStride = 0;

	iData.pSysMem = indices;
	iData.SysMemPitch = 0;
	iData.SysMemSlicePitch = 0;

	result = device->CreateBuffer(&iBufferDesc, &iData, &m_iBuffer);
	if (FAILED(result))
	{

	}

	delete[] vertices;
	vertices = 0;
	delete[] indices;
	indices = 0;
}

void DXMesh::Render(ID3D11DeviceContext* context)
{
	RenderBuffers(context);
}

void DXMesh::RenderBuffers(ID3D11DeviceContext* context)
{
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(Vertex);
	offset = 0;

	context->IASetVertexBuffers(0, 1, &m_vBuffer, &stride, &offset);
	context->IASetIndexBuffer(m_iBuffer, DXGI_FORMAT_R32_UINT, 0);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}
