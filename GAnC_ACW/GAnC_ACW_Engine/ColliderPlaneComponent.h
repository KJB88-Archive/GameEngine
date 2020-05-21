#pragma once
#include "Vector3.h"
#include "BaseColliderComponent.h"

class ColliderPlaneComponent
	: public BaseColliderComponent
{
public:
	ColliderPlaneComponent(Entity* owner);
	virtual ~ColliderPlaneComponent();

	Vector3 collisionSurface;

};