#include "ColliderPlaneComponent.h"
#include "Entity.h"

ColliderPlaneComponent::ColliderPlaneComponent(Entity* owner)
	: BaseColliderComponent("ColliderPlane", BaseColliderComponent::ColliderType::PLANE, owner)
{
	owner->AddComponent(this);
}

ColliderPlaneComponent::~ColliderPlaneComponent()
{

}
