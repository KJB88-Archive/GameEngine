#pragma once
#include <string>

class IComponent
{
public:

	IComponent(const int id, const std::string& name) {};
	~IComponent() {};

	enum ComponentTypes
	{
		COMPONENT_NONE = 0,
		COMPONENT_TRANSFORM = 1 << 0,
		COMPONENT_RENDER = 1 << 1,

	};

	virtual ComponentTypes ComponentType() = 0;

protected:

	ComponentTypes componentType;

private:
	
	IComponent(const IComponent& other);
};