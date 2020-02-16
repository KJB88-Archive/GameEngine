#pragma once
#include <vector>
#include "Entity.h"
#include "IComponent.h"

class ISystem
{
public:
	enum SystemType
	{
		INPUT,
		RENDER,
		PHYSICS
	};

	ISystem(SystemType type)
		: systemType(type)
	{

	}

	SystemType GetType()
	{
		return systemType;
	}

	virtual void ProcessEntities(std::vector<Entity*> entities) = 0;

protected:

	SystemType systemType;
};