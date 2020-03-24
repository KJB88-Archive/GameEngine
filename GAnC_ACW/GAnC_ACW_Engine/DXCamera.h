#pragma once
#include <DirectXMath.h>
#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"

class DXCamera
{
public:

	DXCamera(const int screenWidth, const int screenHeight, const float screenNear, const float screenDepth);
	//DXCamera(const DXCamera&);
	~DXCamera();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	DirectX::XMFLOAT3 GetPosition();
	DirectX::XMFLOAT3 GetRotation();

	void Render();
	void GetViewMatrix(DirectX::XMMATRIX&);
	void GetProjectionMatrix(DirectX::XMMATRIX&);
	void GetOrthographicMatrix(DirectX::XMMATRIX&);

private:

	const float fieldOfView;

	float m_posX, m_posY, m_posZ;
	float m_rotX, m_rotY, m_rotZ;
	DirectX::XMMATRIX m_view;
	DirectX::XMMATRIX m_proj;
	DirectX::XMMATRIX m_ortho;
};