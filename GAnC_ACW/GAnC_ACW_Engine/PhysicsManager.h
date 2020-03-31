#pragma once
#include "Manager.h"
#include "Vector3.h"

class PhysicsSystem;

class PhysicsManager
	: public Manager
{
public:

	PhysicsManager();
	virtual ~PhysicsManager();

	Vector3 CalculateNewPositions(Vector3 position);

	PhysicsSystem* GetSystem();

private:

	TimeManager* m_timeManager;
	PhysicsSystem* m_physicsSystem;
};