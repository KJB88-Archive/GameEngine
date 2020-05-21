#pragma once
#include "BaseColliderComponent.h"

class ColliderSphereComponent
	: public BaseColliderComponent
{
public:
	ColliderSphereComponent(Entity* owner);
	virtual ~ColliderSphereComponent();

	float radius;
};