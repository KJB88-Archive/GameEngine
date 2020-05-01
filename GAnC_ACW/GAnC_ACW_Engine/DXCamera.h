#pragma once
#include <DirectXMath.h>
#include "Camera.h"

class DXCamera
	: public Camera
{
public:

	DXCamera(const int screenWidth, const int screenHeight, const float screenNear, const float screenDepth);
	~DXCamera();

	//void SetPosition(float, float, float);
	//void SetRotation(float, float, float);

	//DirectX::XMFLOAT3 GetPosition();
	//DirectX::XMFLOAT3 GetRotation();

	//virtual void UpdateEyePosition(Vector3 eyePos) override;
	//virtual void UpdateLookAtPosition(Vector3 lookAt) override;
	//virtual void UpdateUpVector(Vector3 up) override;
	//virtual void UpdateYaw(float yaw) override;
	//virtual void UpdatePitch(float pitch) override;
	//virtual void UpdateRoll(float roll) override;
	//virtual void Update() override;
	//virtual void Translate(Vector3 newPos) override;
	//virtual void Rotate(Vector3 axis, float degrees) override;

	void Render();

	void GetViewMatrix(DirectX::XMMATRIX&);
	void GetProjectionMatrix(DirectX::XMMATRIX&);
	void GetOrthographicMatrix(DirectX::XMMATRIX&);

private:

	const float fieldOfView;

	DirectX::XMVECTOR camRight;
	DirectX::XMVECTOR camFwd;
	float moveLeftRight = 0.0f;
	float moveBackForward = 0.0f;

	const DirectX::XMVECTOR FWD = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	const DirectX::XMVECTOR RIGHT = DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	DirectX::XMVECTOR m_dxEyePos;
	DirectX::XMVECTOR m_dxLookAt;
	DirectX::XMVECTOR m_dxUp;
	DirectX::XMMATRIX m_dxRotMatrix;

	DirectX::XMMATRIX m_view;
	DirectX::XMMATRIX m_proj;
	DirectX::XMMATRIX m_ortho;
};