#pragma once
#include "BaseComponent.h"

class BaseColliderComponent
	: public BaseComponent
{
public:

	enum ColliderType
	{
		PLANE,
		SPHERE
	};

	BaseColliderComponent(std::string name, ColliderType type, Entity* owner)
		: BaseComponent(name, BaseComponent::ComponentType::COMPONENT_COLLIDER, owner), colliderType(type) {};

	virtual ~BaseColliderComponent() {};

	ColliderType colliderType;
};