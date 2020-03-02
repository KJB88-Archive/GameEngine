#include "DXCamera.h"

using namespace DirectX;

DXCamera::DXCamera()
	:m_posX(0.0f), m_posY(0.0f), m_posZ(0.0f), m_rotX(0.0f), m_rotY(0.0f), m_rotZ(0.0f)
{

}

DXCamera::~DXCamera()
{

}

void DXCamera::SetPosition(float x, float y, float z)
{
	m_posX = x;
	m_posY = y;
	m_posZ = z;
}

void DXCamera::SetRotation(float x, float y, float z)
{
	m_rotX = x;
	m_rotY = y;
	m_rotZ = z;
}

XMFLOAT3 DXCamera::GetPosition()
{
	return XMFLOAT3(m_posX, m_posY, m_posZ);
}

XMFLOAT3 DXCamera::GetRotation()
{
	return XMFLOAT3(m_rotX, m_rotY, m_rotZ);
}

void DXCamera::GetViewMatrix(XMMATRIX& view)
{
	view = m_view;
}

void DXCamera::Render()
{
	XMFLOAT3 up, eye, lookAt;
	XMVECTOR upVector, eyeVector, lookAtVector;
	float yaw, pitch, roll;
	XMMATRIX rotationMatrix;

	// Up
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	upVector = XMLoadFloat3(&up);

	// Eye
	eye.x = m_posX;
	eye.y = m_posY;
	eye.z = m_posZ;
	eyeVector = XMLoadFloat3(&eye);

	// Lookat
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;
	lookAtVector = XMLoadFloat3(&lookAt);

	// Rotation
	pitch = m_rotX * 0.0174532925f;
	yaw = m_rotY * 0.0174532925f;
	roll = m_rotZ * 0.0174532925f;
	rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

	// Correct vectors due to rotation
	lookAtVector = XMVector3TransformCoord(lookAtVector, rotationMatrix);
	upVector = XMVector3TransformCoord(upVector, rotationMatrix);

	// Translate to location of viewer
	lookAtVector = XMVectorAdd(eyeVector, lookAtVector);

	m_view = XMMatrixLookAtLH(eyeVector, lookAtVector, upVector);
}