#pragma once
#include <D3D11.h>
#include <DirectXMath.h>

class DXMesh
{

public:

	DXMesh(ID3D11Device*);
	DXMesh(const DXMesh&);
	~DXMesh();

	int GetIndexCount() { return m_iCount; }

	void Render(ID3D11DeviceContext* context);
private:

	struct Vertex
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT4 color;
	};

	void InitializeBuffers(ID3D11Device*);
	void RenderBuffers(ID3D11DeviceContext*);

	ID3D11Buffer *m_vBuffer, *m_iBuffer;
	int m_vCount, m_iCount;
};