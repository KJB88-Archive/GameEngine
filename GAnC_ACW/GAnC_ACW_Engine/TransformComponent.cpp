#include "TransformComponent.h"

TransformComponent::TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale)
	: IComponent(COMPONENT_TRANSFORM), position(pos), rotation(rot), scale(scale)
{
}

TransformComponent::~TransformComponent()
{
	
}

IComponent::ComponentTypes TransformComponent::ComponentType()
{
	return componentType;
}
