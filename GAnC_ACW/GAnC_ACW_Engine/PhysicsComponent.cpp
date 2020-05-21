#include "PhysicsComponent.h"
#include "Entity.h"

PhysicsComponent::PhysicsComponent(Entity* owner)
	: BaseComponent("Physics", COMPONENT_PHYSICS, owner)
{
	owner->AddComponent(this);
}

PhysicsComponent::~PhysicsComponent()
{

}