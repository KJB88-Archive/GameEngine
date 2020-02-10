#pragma once
#include <vector>
#include "Entity.h"

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

	virtual SystemType Type() = 0;
	virtual void ProcessEntities(std::vector<Entity> entities) = 0;

private:

	SystemType systemType;
};