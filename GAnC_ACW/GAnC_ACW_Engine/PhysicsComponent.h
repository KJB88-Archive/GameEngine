#pragma once
#include "Component.h"
#include "Vector3.h"

class PhysicsComponent
	: public Component
{

public:

	PhysicsComponent(Entity* owner);
	virtual ~PhysicsComponent();

	float mass;
	Vector3 velocity;
	Vector3 acceleration;

private:

};