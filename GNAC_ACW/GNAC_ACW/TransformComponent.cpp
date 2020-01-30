#include "TransformComponent.h"

TransformComponent::TransformComponent()
	: position(Vector3(0.0f, 0.0f, 0.0f)), rotation(Vector3(0.0f, 0.0f, 0.0f)), scale(Vector3(1.0f, 1.0f, 1.0f)), parent(nullptr)
{
}

TransformComponent::TransformComponent(Vector3 pos)
	: position(pos), rotation(Vector3(0.0f, 0.0f, 0.0f)), scale(Vector3(1.0f, 1.0f, 1.0f)), parent(nullptr)
{

}

TransformComponent::TransformComponent(Vector3 pos, Vector3 rot)
	: position(pos), rotation(rot), scale(Vector3(1.0f, 1.0f, 1.0f)), parent(nullptr)
{

}

TransformComponent::TransformComponent(Vector3 pos, Vector3 rot, Vector3 scale)
	: position(pos), rotation(rot), scale(scale), parent(nullptr)
{

}

TransformComponent::~TransformComponent()
{
	
}

void TransformComponent::SetParent(TransformComponent* newParent)
{
	parent = newParent;
}

TransformComponent* TransformComponent::GetParent()
{
	return parent;
}