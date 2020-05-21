#pragma once
#include "BaseComponent.h"
#include "Vector3.h"

class PhysicsComponent
	: public BaseComponent
{

public:

	PhysicsComponent(Entity* owner);
	virtual ~PhysicsComponent();

	float mass;
	Vector3 velocity;

private:

};