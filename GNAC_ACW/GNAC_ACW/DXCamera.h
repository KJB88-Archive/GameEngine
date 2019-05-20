#pragma once
#include <DirectXMath.h>

class DXCamera
{
public:

	DXCamera();
	DXCamera(const DXCamera&);
	~DXCamera();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	DirectX::XMFLOAT3 GetPosition();
	DirectX::XMFLOAT3 GetRotation();

	void Render();
	void GetViewMatrix(DirectX::XMMATRIX&);

private:
	float m_posX, m_posY, m_posZ;
	float m_rotX, m_rotY, m_rotZ;
	DirectX::XMMATRIX m_view;
};