#pragma once
#include <string>
#include "Logger.h"
class Entity;

class BaseComponent
{

public:

	static enum ComponentType
	{
		COMPONENT_NONE = 0,
		COMPONENT_TRANSFORM = 1 << 0,
		COMPONENT_RENDER = 1 << 1,
		COMPONENT_PHYSICS = 1 << 2,
		COMPONENT_COLLIDER = 1 << 3
	};

	BaseComponent(std::string name, ComponentType type, Entity* owner)
		: m_type(type), m_owner(owner) {};
	virtual ~BaseComponent() { m_owner = nullptr; };

	std::string GetName() { return m_name; }
	ComponentType GetType() { return m_type; }
	Entity* GetOwner() { return m_owner; }

protected:

	const std::string m_name;
	const ComponentType m_type;
	Entity* m_owner;

private:

	BaseComponent(const BaseComponent& other);
};

inline BaseComponent::ComponentType operator|(BaseComponent::ComponentType a, BaseComponent::ComponentType b)
{
	return static_cast<BaseComponent::ComponentType>(static_cast<int>(a) | static_cast<int>(b));
}