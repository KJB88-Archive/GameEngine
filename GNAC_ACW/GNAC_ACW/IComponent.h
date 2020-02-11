#pragma once
#include <string>

class IComponent
{

public:

	enum ComponentTypes
	{
		COMPONENT_NONE = 0,
		COMPONENT_TRANSFORM = 1 << 0,
		COMPONENT_RENDER = 1 << 1,

	};

	IComponent(ComponentTypes type)
	{
		componentType = type;
	};

	~IComponent() {};
	virtual ComponentTypes ComponentType() = 0;


protected:

	ComponentTypes componentType;

private:
	
	IComponent(const IComponent& other);
};

inline IComponent::ComponentTypes operator|(IComponent::ComponentTypes a, IComponent::ComponentTypes b)
{
	return static_cast<IComponent::ComponentTypes>(static_cast<int>(a) | static_cast<int>(b));
}