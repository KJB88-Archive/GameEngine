#pragma once
#include "BaseComponent.h"
#include "DXCamera.h"

class CameraComponent
	: public BaseComponent
{
public:

	CameraComponent(Entity* owner);
	virtual ~CameraComponent();

	Camera* GetCamera();
	void SetCamera(Camera* camera);

private:

#ifdef DX_BUILD
	DXCamera* m_camera;
#else
	GLCamera* m_camera;
#endif
};