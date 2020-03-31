#pragma once
#include <vector>
#include "BaseComponent.h"
class Entity;

class BaseSystem
{
public:
	enum SystemType
	{
		INPUT,
		RENDER,
		PHYSICS
	};

	BaseSystem(std::string systemName, SystemType type)
		: m_name(systemName), m_type(type) {};
	virtual ~BaseSystem() {};

	std::string GetName() { return m_name; }
	SystemType GetType(){ return m_type; }

	virtual void ProcessEntities(std::vector<Entity*> entities) = 0;

protected:

	std::string m_name;
	SystemType m_type;
};