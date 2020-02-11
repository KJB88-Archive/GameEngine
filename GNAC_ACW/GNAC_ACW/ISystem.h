#pragma once
#include <vector>
#include "Entity.h"
#include "IComponent.h"

class ISystem
{
public:


	enum SystemType
	{
		SYSTEM_TRANSFORM,
		SYSTEM_RENDER,
	};

	ISystem(SystemType type)
	{
		systemType = type;
	}

	virtual SystemType GetType() = 0;
	virtual void ProcessEntities(std::vector<Entity*> entities) = 0;

protected:
	SystemType systemType;
};