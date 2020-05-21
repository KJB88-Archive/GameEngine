#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>

// Load D3D libraries
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <fstream>

#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"

class DXRenderer;

class DXShader
{
public:

	DXShader(DXRenderer* renderer);
	~DXShader();

	void Render(ID3D11DeviceContext*, int, DirectX::XMMATRIX&, DirectX::XMMATRIX&, DirectX::XMMATRIX&);

private:
	
	void SetShaderParameters(ID3D11DeviceContext*, DirectX::XMMATRIX&, DirectX::XMMATRIX&, DirectX::XMMATRIX&);
	void RenderShader(ID3D11DeviceContext*, int);

	struct MatrixBuffer
	{
		DirectX::XMMATRIX world;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX proj;
	};

	ID3D11VertexShader* m_vShader;
	ID3D11PixelShader* m_pShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_cbWVP;

	DXShader(const DXShader&) = delete;
	DXShader* operator=(const DXShader&) = delete;
};