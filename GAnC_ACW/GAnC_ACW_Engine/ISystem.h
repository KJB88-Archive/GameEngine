#pragma once
#include <vector>
#include "Component.h"
class Entity;

class ISystem
{
public:
	enum SystemType
	{
		INPUT,
		RENDER,
		PHYSICS,
		CAMERA
	};

	ISystem(SystemType type)
		: m_type(type) {};
	virtual ~ISystem() {};

	SystemType GetType(){ return m_type; }

	virtual void ProcessEntities(std::vector<Entity*> entities) = 0;

protected:

	SystemType m_type;
};