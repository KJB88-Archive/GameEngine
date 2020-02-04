#include "TransformComponent.h"

TransformComponent::TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale)
	: IComponent(0, "Transform"), position(pos), rotation(rot), scale(scale)
{
	IComponent::componentType = COMPONENT_TRANSFORM;
	
	// TODO - Apply ID from constant source (eg EntityManager)
}

TransformComponent::~TransformComponent()
{
	
}

IComponent::ComponentTypes TransformComponent::ComponentType()
{
	return componentType;
}
