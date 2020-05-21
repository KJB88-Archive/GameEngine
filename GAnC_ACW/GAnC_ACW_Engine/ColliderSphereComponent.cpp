#include "ColliderSphereComponent.h"
#include "Entity.h"

ColliderSphereComponent::ColliderSphereComponent(Entity* owner)
	: BaseColliderComponent("ColliderSphere", BaseColliderComponent::ColliderType::SPHERE, owner)
{
	owner->AddComponent(this);
}

ColliderSphereComponent::~ColliderSphereComponent()
{

}