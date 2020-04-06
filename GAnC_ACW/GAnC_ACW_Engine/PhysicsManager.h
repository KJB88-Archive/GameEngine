#pragma once
#include "Manager.h"
#include "Vector3.h"
#include "PhysicsSystem.h"


class PhysicsManager
	: public Manager
{
public:

	PhysicsManager();
	virtual ~PhysicsManager();

	Vector3 CalculateNewPositions(Vector3 position);

	PhysicsSystem* GetSystem();

private:

	PhysicsSystem* m_physicsSystem;
};