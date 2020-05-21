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

	void ApplyPhysics(Vector3& position, Vector3& velocity);

	PhysicsSystem* GetSystem();
private:

	void ApplyConstants(Vector3& velocity);

	const float m_grav;

	 PhysicsSystem* m_physicsSystem;
};