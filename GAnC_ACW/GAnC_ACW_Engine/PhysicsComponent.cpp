#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(Entity* owner)
	: BaseComponent("Physics", COMPONENT_PHYSICS, owner)
{

}

PhysicsComponent::~PhysicsComponent()
{

}