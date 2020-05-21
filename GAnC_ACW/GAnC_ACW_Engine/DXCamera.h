#pragma once
#include <DirectXMath.h>
#include "Camera.h"

class DXCamera
	: public Camera
{
public:

	DXCamera(const int screenWidth, const int screenHeight, const float screenNear, const float screenDepth);
	~DXCamera();

	void Render();

	void GetViewMatrix(DirectX::XMMATRIX&);
	void GetProjectionMatrix(DirectX::XMMATRIX&);
	void GetOrthographicMatrix(DirectX::XMMATRIX&);

private:

	// Current axis alignment
	DirectX::XMVECTOR camRight;
	DirectX::XMVECTOR camFwd;
	DirectX::XMVECTOR camUp;

	// DX transformation vars
	DirectX::XMVECTOR camPos;
	DirectX::XMVECTOR lookAtPos;
	DirectX::XMMATRIX rotationMatrix;

	// Temporary movement vars
	float moveLeftRight = 0.0f;
	float moveBackForward = 0.0f;
	float moveUpDown = 0.0f;

	// Speed Modifiers
	float m_translationSpeed = 20.0f;
	float m_rotationSpeed = 15.0f;

	// True Axis alignment
	const DirectX::XMVECTOR FWD = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	const DirectX::XMVECTOR RIGHT = DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	const DirectX::XMVECTOR UP = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0);

	// Debug Vars (Initial starting values)
	const DirectX::XMVECTOR LOOKAT = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	const DirectX::XMVECTOR EYEPOS = DirectX::XMVectorSet(0.0f, 25.0f, -50.0f, 0.0f);

	// Rendering vars
	const float fieldOfView;

	DirectX::XMMATRIX m_view;
	DirectX::XMMATRIX m_proj;
	DirectX::XMMATRIX m_ortho;
};