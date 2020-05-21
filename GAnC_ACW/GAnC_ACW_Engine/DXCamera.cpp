#include "DXCamera.h"
using namespace DirectX;

#include "InputManager.h"
#include "TimeManager.h"

DXCamera::DXCamera(const int screenWidth, const int screenHeight, const float screenNear, const float screenDepth)
	: Camera(), fieldOfView(XM_PIDIV4)
{
	float FoV, aspectRatio;

	// Proj
	FoV = XM_PIDIV4;
	aspectRatio = (float)screenWidth / (float)screenHeight;

	m_proj = XMMatrixPerspectiveFovLH(FoV, aspectRatio, screenNear, screenDepth);

	// Ortho
	m_ortho = XMMatrixOrthographicLH((float)screenWidth, (float)screenHeight, screenNear, screenDepth);

	camPos = EYEPOS;
	camUp = UP;
	lookAtPos = LOOKAT;

	m_pitch = 0.5f;
}

DXCamera::~DXCamera()
{

}

void DXCamera::GetViewMatrix(XMMATRIX& view)
{
	view = m_view;
}

void DXCamera::GetProjectionMatrix(DirectX::XMMATRIX& proj)
{
	proj = m_proj;
}

void DXCamera::GetOrthographicMatrix(DirectX::XMMATRIX& ortho)
{
	ortho = m_ortho;
}

void DXCamera::Render()
{
	double dt = TimeManager::GetDeltaTime();

	// X
	if (InputManager::GetButtonDown("Left"))
	{
		moveLeftRight -= m_translationSpeed * dt;
	}
	else if (InputManager::GetButtonDown("Right"))
	{
		moveLeftRight += m_translationSpeed * dt;
	}

	// Z
	if (InputManager::GetButtonDown("Forward"))
	{
		moveBackForward += m_translationSpeed * dt;
	}
	else if (InputManager::GetButtonDown("Backward"))
	{
		moveBackForward -= m_translationSpeed * dt;
	}

	// Y
	if (InputManager::GetButtonDown("Up"))
	{
		moveUpDown += m_translationSpeed * dt;
	}
	else if (InputManager::GetButtonDown("Down"))
	{
		moveUpDown -= m_translationSpeed * dt;
	}

	// YAW
	if (InputManager::GetButtonDown("YawLeft"))
	{
		m_yaw -= m_rotationSpeed * dt;
	}
	else if (InputManager::GetButtonDown("YawRight"))
	{
		m_yaw += m_rotationSpeed * dt;
	}

	// PITCH
	if (InputManager::GetButtonDown("PitchUp"))
	{
		m_pitch -= m_rotationSpeed * dt;
	}
	else if (InputManager::GetButtonDown("PitchDown"))
	{
		m_pitch += m_rotationSpeed * dt;
	}

	// Camera Movement basis from Brayznarsoft template
	rotationMatrix = XMMatrixRotationRollPitchYaw(m_pitch, m_yaw, m_roll);
	lookAtPos = XMVector3TransformCoord(FWD, rotationMatrix);
	lookAtPos = XMVector3Normalize(lookAtPos);

	XMMATRIX RotateYTempMatrix;
	RotateYTempMatrix = XMMatrixRotationY(m_yaw);

	camRight = XMVector3TransformCoord(RIGHT, RotateYTempMatrix);
	camUp = XMVector3TransformCoord(UP, RotateYTempMatrix);
	camFwd = XMVector3TransformCoord(FWD, RotateYTempMatrix);

	camPos += moveLeftRight * camRight;
	camPos += moveBackForward * camFwd;
	camPos += moveUpDown * camUp;

	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;
	moveUpDown = 0.0f;

	lookAtPos = camPos + lookAtPos;

	m_view = XMMatrixLookAtLH(camPos, lookAtPos, camUp);
}