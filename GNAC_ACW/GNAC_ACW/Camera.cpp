#include "Camera.h"

Camera* Camera::main = nullptr;

Camera::Camera()
	: Component("Camera"), fieldOfView(0.0f), nearClip(0.0f), farClip(0.0f)
{
	if (main == nullptr)
	{
		main = this;
	}
}

Camera::~Camera()
{
	if (main == this)
	{
		main = nullptr;
	}
}

Camera* Camera::GetMainCamera()
{
	return main;
}

void Camera::SetMain()
{
	main = this;
}

float Camera::GetFoV()
{
	return fieldOfView;
}