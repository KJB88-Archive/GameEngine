//#include "DX_VBO.h"
//
//#include "Graphics.h"
//
//using namespace DirectX;
//
//DX_VBO::DX_VBO()
//{
//
//}
//
//DX_VBO::~DX_VBO()
//{
//
//}
//
//void DX_VBO::Create(Graphics * graphics, VertexStruct vertices[], int noOfVerts)
//{
//	VertexStruct* vertices;
//	unsigned long* indices;
//	D3D11_BUFFER_DESC vBufferDesc, iBufferDesc;
//	D3D11_SUBRESOURCE_DATA vData, iData;
//	HRESULT result;
//
//	m_vCount = 4;
//	m_iCount = 6;
//
//	vertices = new VertexStruct[m_vCount];
//	indices = new unsigned long[m_iCount];
//
//	vertices[0].position = XMFLOAT3(1.0f, 1.0f, 0.0f);
//	vertices[1].position = XMFLOAT3(-1.0f, 1.0f, 0.0f);
//	vertices[2].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);
//	vertices[3].position = XMFLOAT3(1.0f, -1.0f, 0.0f);
//
//	//vertices[4].position = XMFLOAT3(0.0f, 0.0f, 1.0f);
//	//vertices[5].position = XMFLOAT3(1.0f, 0.0f, 1.0f);
//	//vertices[6].position = XMFLOAT3(1.0f, 1.0f, 1.0f);
//	//vertices[7].position = XMFLOAT3(0.0f, 1.0f, 1.0f);
//
//	for (int i = 0; i < m_vCount; ++i)
//	{
//		vertices[i].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
//	}
//
//	indices[0] = 0;
//	indices[1] = 3;
//	indices[2] = 2;
//	indices[3] = 2;
//	indices[4] = 1;
//	indices[5] = 0;
//
//
//	vBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//	vBufferDesc.ByteWidth = sizeof(Vertex) * m_vCount;
//	vBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//	vBufferDesc.CPUAccessFlags = 0;
//	vBufferDesc.MiscFlags = 0;
//	vBufferDesc.StructureByteStride = 0;
//
//	// Give subresource data
//	vData.pSysMem = vertices;
//	vData.SysMemPitch = 0;
//	vData.SysMemSlicePitch = 0;
//
//	device->CreateBuffer(&vBufferDesc, &vData, &m_vBuffer);
//
//	iBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//	iBufferDesc.ByteWidth = sizeof(unsigned long) * m_iCount;
//	iBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
//	iBufferDesc.CPUAccessFlags = 0;
//	iBufferDesc.MiscFlags = 0;
//	iBufferDesc.StructureByteStride = 0;
//
//	iData.pSysMem = indices;
//	iData.SysMemPitch = 0;
//	iData.SysMemSlicePitch = 0;
//
//	result = device->CreateBuffer(&iBufferDesc, &iData, &m_iBuffer);
//	if (FAILED(result))
//	{
//
//	}
//
//	delete[] vertices;
//	vertices = 0;
//	delete[] indices;
//	indices = 0;
//}
//
//void DX_VBO::Draw(Graphics * graphics)
//{
//
//}
