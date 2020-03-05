#pragma once
#include <string>

class Entity;

class Component
{

public:

	enum ComponentTypes
	{
		COMPONENT_NONE = 0,
		COMPONENT_TRANSFORM = 1 << 0,
		COMPONENT_RENDER = 1 << 1,

	};

	Component(ComponentTypes type, Entity* owner)
		: m_type(type), m_owner(owner) {};
	virtual ~Component() { m_owner = nullptr; };

	ComponentTypes ComponentType() { return m_type; }

protected:

	ComponentTypes m_type;
	Entity* m_owner;

private:
	
	Component(const Component& other);
};

inline Component::ComponentTypes operator|(Component::ComponentTypes a, Component::ComponentTypes b)
{
	return static_cast<Component::ComponentTypes>(static_cast<int>(a) | static_cast<int>(b));
}