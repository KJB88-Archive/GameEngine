#pragma once
#include "VBO.h"
#include <wrl.h>

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>

class DXRenderer;

class VBO_DX
	: public VBO
{
public:

	VBO_DX();
	virtual ~VBO_DX();

	virtual void Create(Graphics* gm, Vertex vertices[], int noOfVerts);
	virtual void Draw(Graphics* gm);

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_vbo;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_indexBuffer;
	unsigned long* m_indices;
};