#pragma once
#include "BaseSystem.h"

class PhysicsManager;

class PhysicsSystem
	: public BaseSystem
{

public:
	PhysicsSystem(PhysicsManager* physics);
	virtual ~PhysicsSystem();

	virtual void ProcessEntities(std::vector<Entity*> entities) override;

private:

	PhysicsManager* m_physics;
};

