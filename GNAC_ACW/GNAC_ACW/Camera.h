#pragma once
#include "Component.h"
#include "Vector3.h"

class Camera
	: public Component
{
public:

	Camera();
	virtual ~Camera();

	static Camera* GetMainCamera();
	float GetFoV();

	void SetMain();

private:

	static Camera* main;

	float fieldOfView;
	float nearClip;
	float farClip;

	Vector3 viewMatrix;

};