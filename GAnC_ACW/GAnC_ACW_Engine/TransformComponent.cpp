#include "TransformComponent.h"

TransformComponent::TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale, Entity* owner)
	: Component(COMPONENT_TRANSFORM, owner), position(pos), rotation(rot), scale(scale)
{
}

TransformComponent::~TransformComponent()
{

}
