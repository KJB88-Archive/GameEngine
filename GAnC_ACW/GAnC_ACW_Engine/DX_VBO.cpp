#include "DX_VBO.h"
#include "DXRenderer.h"

using namespace DirectX;

DX_VBO::DX_VBO()
{

}

DX_VBO::~DX_VBO()
{

}

void DX_VBO::Create(Renderer* renderer, std::vector<Vertex> vertices, int noOfVerts)
{
	DXRenderer* dxRenderer = dynamic_cast<DXRenderer*>(renderer);

	DXVertex* dxVerts;
	unsigned long* indices;
	D3D11_BUFFER_DESC vBufferDesc, iBufferDesc;
	D3D11_SUBRESOURCE_DATA vData, iData;
	HRESULT result;

	// Convert from generic struct to DX specific struct
	// TODO 
	m_vCount = 4;
	m_iCount = 6;

	dxVerts = new DXVertex[m_vCount];
	indices = new unsigned long[m_iCount];

	dxVerts[0].position = XMFLOAT3(1.0f, 1.0f, 0.0f);
	dxVerts[1].position = XMFLOAT3(-1.0f, 1.0f, 0.0f);
	dxVerts[2].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);
	dxVerts[3].position = XMFLOAT3(1.0f, -1.0f, 0.0f);

	//dxVerts[4].position = XMFLOAT3(-1.0f, 0.0f, 1.0f);
	//dxVerts[5].position = XMFLOAT3(1.0f, 0.0f, 1.0f);
	//dxVerts[6].position = XMFLOAT3(1.0f, 1.0f, 1.0f);
	//dxVerts[7].position = XMFLOAT3(-1.0f, 1.0f, 1.0f);

	for (int i = 0; i < m_vCount; ++i)
	{
		dxVerts[i].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	indices[0] = 0;
	indices[1] = 3;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 1;
	indices[5] = 0;

	vBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vBufferDesc.ByteWidth = sizeof(DXVertex) * m_vCount;
	vBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vBufferDesc.CPUAccessFlags = 0;
	vBufferDesc.MiscFlags = 0;
	vBufferDesc.StructureByteStride = 0;

	// Give subresource data
	vData.pSysMem = dxVerts;
	vData.SysMemPitch = 0;
	vData.SysMemSlicePitch = 0;

	dxRenderer->GetDevice()->CreateBuffer(&vBufferDesc, &vData, &m_vBuffer);

	iBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	iBufferDesc.ByteWidth = sizeof(unsigned long) * m_iCount;
	iBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	iBufferDesc.CPUAccessFlags = 0;
	iBufferDesc.MiscFlags = 0;
	iBufferDesc.StructureByteStride = 0;

	iData.pSysMem = indices;
	iData.SysMemPitch = 0;
	iData.SysMemSlicePitch = 0;

	result = dxRenderer->GetDevice()->CreateBuffer(&iBufferDesc, &iData, &m_iBuffer);
	if (FAILED(result))
	{
		// check result
	}

	delete dxVerts;
	dxVerts = 0;
	delete[] indices;
	indices = 0;
}

void DX_VBO::Draw(Renderer* renderer)
{
	DXRenderer* dxRenderer = dynamic_cast<DXRenderer*>(renderer);

	// select which vertex buffer to display
	UINT stride = sizeof(DXVertex);
	UINT offset = 0;

	dxRenderer->GetContext()->IASetVertexBuffers(0, 1, &m_vBuffer, &stride, &offset);
	dxRenderer->GetContext()->IASetIndexBuffer(m_iBuffer, DXGI_FORMAT_R32_UINT, 0);

	// select which primtive type we are using
	dxRenderer->GetContext()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}