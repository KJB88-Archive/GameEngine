#pragma once
#include "CameraComponent.h"

CameraComponent::CameraComponent(Entity* owner)
	: BaseComponent("Camera", ComponentType::COMPONENT_CAMERA, owner), m_camera(nullptr)
{

}

CameraComponent::~CameraComponent()
{
	m_camera = nullptr;
}

Camera* CameraComponent::GetCamera()
{
	return m_camera;
}

void CameraComponent::SetCamera(Camera* camera)
{
#ifdef DX_BUILD
	m_camera = dynamic_cast<DXCamera*>(camera);
#else
	m_camera = dynamic_cast<GLCamera*>(camera);
#endif
}
