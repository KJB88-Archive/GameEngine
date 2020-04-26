#include "DX_VBO.h"
#include "DXRenderer.h"

using namespace DirectX;

DX_VBO::DX_VBO()
{

}

DX_VBO::~DX_VBO()
{

}

void DX_VBO::Create(Renderer* renderer, std::vector<Vertex> vertices, std::vector<int> indices)
{
	DXRenderer* dxRenderer = dynamic_cast<DXRenderer*>(renderer);

	m_vCount = vertices.size();
	m_iCount = indices.size();

	DXVertex* dxVerts;
	dxVerts = new DXVertex[m_vCount];

	unsigned long* dxIndices;
	dxIndices = new unsigned long[indices.size()];

	for (int i = 0; i < vertices.size(); ++i)
	{
		dxVerts[i].position = XMFLOAT3(vertices[i].x, vertices[i].y, vertices[i].z);
		dxVerts[i].color = XMFLOAT4(vertices[i].r, vertices[i].g, vertices[i].b, vertices[i].a);
	}

	for (int i = 0; i < indices.size(); ++i)
	{
		dxIndices[i] = indices[i];
	}

	////dxVerts[0].position = XMFLOAT3(1.0f, 1.0f, -1.0f);
	////dxVerts[1].position = XMFLOAT3(-1.0f, 1.0f, -1.0f);
	////dxVerts[2].position = XMFLOAT3(-1.0f, -1.0f, -1.0f);
	////dxVerts[3].position = XMFLOAT3(1.0f, -1.0f, -1.0f);
	////dxVerts[4].position = XMFLOAT3(-1.0f, -1.0f, 1.0f);
	////dxVerts[5].position = XMFLOAT3(1.0f, -1.0f, 1.0f);
	////dxVerts[6].position = XMFLOAT3(1.0f, 1.0f, 1.0f);
	////dxVerts[7].position = XMFLOAT3(-1.0f, 1.0f, 1.0f);
	//for (int i = 0; i < m_vCount; ++i)
	//{
	//	dxVerts[i].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	//}
	//// Front
	//indices[0] = 0;
	//indices[1] = 3;
	//indices[2] = 2;
	//indices[3] = 2;
	//indices[4] = 1;
	//indices[5] = 0;
	//// Side 1
	//indices[6] = 0;
	//indices[7] =3;
	//indices[8] = 5;
	//indices[9] = 5;
	//indices[10] = 3;
	//indices[11] = 7;
	//// Back
	//indices[12] = 7;
	//indices[13] = 6;
	//indices[14] = 5;
	//indices[15] = 5;
	//indices[16] = 4;
	//indices[17] = 7;
	//// Side 2
	//indices[18] = 1;
	//indices[19] = 2;
	//indices[20] = 4;
	//indices[21] = 4;
	//indices[22] = 6;
	//indices[23] = 2;
	//// Top
	//indices[24] = 2;
	//indices[25] = 3;
	//indices[26] = 6;
	//indices[27] = 6;
	//indices[28] = 7;
	//indices[29] = 2;
	//// Bottom
	//indices[30] = 1;
	//indices[31] = 0;
	//indices[32] = 4;
	//indices[33] = 4;
	//indices[34] = 5;
	//indices[35] = 1;

	D3D11_BUFFER_DESC vBufferDesc;
	vBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vBufferDesc.ByteWidth = sizeof(DXVertex) * m_vCount;
	vBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vBufferDesc.CPUAccessFlags = 0;
	vBufferDesc.MiscFlags = 0;
	vBufferDesc.StructureByteStride = 0;

	// Give subresource data
	D3D11_SUBRESOURCE_DATA vData;
	vData.pSysMem = dxVerts;
	vData.SysMemPitch = 0;
	vData.SysMemSlicePitch = 0;

	HRESULT result =dxRenderer->GetDevice()->CreateBuffer(&vBufferDesc, &vData, &m_vBuffer);
	if (FAILED(result))
	{
		printf("DXVBO: Unable to create vertex buffer. \n");
	}

	D3D11_BUFFER_DESC iBufferDesc;
	iBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	iBufferDesc.ByteWidth = sizeof(unsigned long) * m_iCount;
	iBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	iBufferDesc.CPUAccessFlags = 0;
	iBufferDesc.MiscFlags = 0;
	iBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA iData;
	iData.pSysMem = dxIndices;
	iData.SysMemPitch = 0;
	iData.SysMemSlicePitch = 0;

	result = dxRenderer->GetDevice()->CreateBuffer(&iBufferDesc, &iData, &m_iBuffer);
	if (FAILED(result))
	{
		// check result
		printf("DXVBO: Unable to create index buffer. \n");
	}

	delete dxVerts;
	dxVerts = 0;
	delete[] dxIndices;
	dxIndices = 0;
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