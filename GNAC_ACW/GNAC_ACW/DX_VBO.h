#pragma once
#include "VBO.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>

class DX_VBO
	: public VBO
{
public:

	DX_VBO();
	virtual ~DX_VBO();

	// Inherited via VBO
	virtual void Create(Graphics* graphics, Vertex vertices[], int noOfVerts) override;
	virtual void Draw(Graphics* graphics) override;

private:
	struct DXVertex
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT4 color;
	};

	ID3D11Buffer *m_vBuffer, *m_iBuffer;
	int m_vCount, m_iCount;
};