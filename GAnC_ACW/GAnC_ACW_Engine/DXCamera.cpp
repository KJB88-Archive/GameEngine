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

	XMFLOAT3 eyePos;
	eyePos.x = 0.0f;
	eyePos.y = 0.0f;
	eyePos.z = -5.0f;
	m_dxEyePos = XMLoadFloat3(&eyePos);

	XMFLOAT3 up;
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	m_dxUp = XMLoadFloat3(&up);

	XMFLOAT3 lookAt;
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;
	m_dxLookAt = XMLoadFloat3(&lookAt);

	//UpdateUpVector(Vector3(0.0f, 1.0f, 0.0f));
	//UpdateLookAtPosition(Vector3(0.0f, 0.0f, 1.0f));

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

//void DXCamera::Update()
//{
//
//	//double dt = TimeManager::GetDeltaTime();
//
//	//Vector3 camPos = m_mainCam->GetEyePosition();
//	//float camYaw = m_mainCam->GetYaw();
//
//	//if (InputManager::GetButtonDown("Forward"))
//	//{
//	//	camPos.z += m_camSpeed * dt;
//	//	m_mainCam->Translate(camPos);
//	//}
//	//else if (InputManager::GetButtonDown("Backward"))
//	//{
//	//	camPos.z -= m_camSpeed * dt;
//	//	m_mainCam->Translate(camPos);
//	//}
//
//	//if (InputManager::GetButtonDown("Left"))
//	//{
//	//	camPos.x += m_camSpeed * dt;
//	//	m_mainCam->Translate(camPos);
//	//}
//
//	//else if (InputManager::GetButtonDown("Right"))
//	//{
//	//	camPos.x -= m_camSpeed * dt;
//	//	m_mainCam->Translate(camPos);
//	//}
//
//	//if (InputManager::GetButtonDown("RotateLeft"))
//	//{
//	//	camYaw += m_camRotSpeed * dt;
//	//	m_mainCam->Rotate(Vector3(0.0f, 1.0f, 0.0f), camYaw);
//	//}
//	//else if (InputManager::GetButtonDown("RotateRight"))
//	//{
//	//	camYaw -= m_camRotSpeed * dt;
//	//	m_mainCam->Rotate(Vector3(0.0f, 1.0f, 0.0f), camYaw);
//	//}
//}

//void DXCamera::Translate(Vector3 newVec)
//{
//	m_dxEyePos = XMVector3Transform(m_dxEyePos, XMMatrixTranslation(newVec.x, newVec.y, newVec.z));
//	m_dxLookAt = XMVector3Transform(m_dxLookAt, XMMatrixTranslation(newVec.x, newVec.y, newVec.z));
//	m_dxUp = XMVector3Transform(m_dxUp, XMMatrixTranslation(newVec.x, newVec.y, newVec.z));
//}
//
//void DXCamera::Rotate(Vector3 axis, float degrees)
//{
//	XMFLOAT3 dxAxis;
//	dxAxis.x = axis.x;
//	dxAxis.y = axis.y;
//	dxAxis.z = axis.z;
//	XMVECTOR dxAxisVec;
//	dxAxisVec = XMLoadFloat3(&dxAxis);
//
//	XMVECTOR dxLookAt = XMVector3Transform(m_dxLookAt, XMMatrixRotationAxis(dxAxisVec, XMConvertToRadians(degrees)));
//	XMVECTOR dxUp = XMVector3Transform(m_dxUp, XMMatrixRotationAxis(dxAxisVec, XMConvertToRadians(degrees)));
//
//	m_dxLookAt = XMVectorAdd(m_dxEyePos, dxLookAt);
//	m_dxUp = XMVectorAdd(m_dxEyePos, dxUp);
//}

//void DXCamera::UpdateYaw(float yaw)
//{
//	m_yaw = yaw * XM_PIDIV2;
//}
//
//void DXCamera::UpdatePitch(float pitch)
//{
//	m_pitch = pitch * XM_PIDIV2;
//}
//
//void DXCamera::UpdateRoll(float roll)
//{
//	m_roll = roll * XM_PIDIV2;
//}

//void DXCamera::Render()
//{
//	//// Rotate
////m_dxRotMatrix = XMMatrixRotationRollPitchYaw(m_pitch, m_yaw, m_roll);
//
//////// Correct vectors due to rotation
//////m_dxLookAt = XMVector3TransformCoord(m_dxLookAt, m_dxRotMatrix);
//////m_dxUp = XMVector3TransformCoord(m_dxUp, m_dxRotMatrix);
//
////// Update view matrix with deltas
////m_view = XMMatrixLookAtLH(m_dxEyePos, m_dxLookAt, m_dxUp);
//}

void DXCamera::Render()
{
	if (InputManager::GetButtonDown("Left"))
	{
		moveLeftRight -= 10.0f * TimeManager::GetDeltaTime();
	}
	else if (InputManager::GetButtonDown("Right"))
	{
		moveLeftRight += 10.0f * TimeManager::GetDeltaTime();
	}

	if (InputManager::GetButtonDown("Forward"))
	{
		moveBackForward += 10.0f * TimeManager::GetDeltaTime();
	}
	else if (InputManager::GetButtonDown("Backward"))
	{
		moveBackForward -= 10.0f * TimeManager::GetDeltaTime();
	}

	if (InputManager::GetButtonDown("RotateLeft"))
	{
		m_yaw -= 2.5f * TimeManager::GetDeltaTime();
	}
	else if (InputManager::GetButtonDown("RotateRight"))
	{
		m_yaw += 2.5f * TimeManager::GetDeltaTime();
	}

	m_dxRotMatrix = XMMatrixRotationRollPitchYaw(m_pitch, m_yaw, m_roll);
	m_dxLookAt = XMVector3TransformCoord(FWD, m_dxRotMatrix);
	m_dxLookAt = XMVector3Normalize(m_dxLookAt);

	XMMATRIX RotateYTempMatrix;
	RotateYTempMatrix = XMMatrixRotationY(m_yaw);

	camRight = XMVector3TransformCoord(RIGHT, RotateYTempMatrix);
	m_dxUp = XMVector3TransformCoord(m_dxUp, RotateYTempMatrix);
	camFwd = XMVector3TransformCoord(FWD, RotateYTempMatrix);

	m_dxEyePos += moveLeftRight * camRight;
	m_dxEyePos += moveBackForward * camFwd;

	moveLeftRight = 0.0f;
	moveBackForward = 0.0f;

	m_dxLookAt = m_dxEyePos + m_dxLookAt;

	m_view = XMMatrixLookAtLH(m_dxEyePos, m_dxLookAt, m_dxUp);
}