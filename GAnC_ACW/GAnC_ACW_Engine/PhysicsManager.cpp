#include "PhysicsManager.h"
#include "TimeManager.h"
#include "PhysicsSystem.h"

#include <iostream>

PhysicsManager::PhysicsManager()
	: Manager("Physics"), m_grav(-9.81f)
{
	m_physicsSystem = new PhysicsSystem(this);
}

PhysicsManager::~PhysicsManager()
{

}

PhysicsSystem* PhysicsManager::GetSystem()
{
	return m_physicsSystem;
}

void PhysicsManager::ApplyPhysics(Vector3& position, Vector3& velocity)
{
	ApplyConstants(velocity);

	velocity = velocity * TimeManager::GetDeltaTime();

	position = position + velocity;
}

void PhysicsManager::ApplyConstants(Vector3& velocity)
{
	velocity.y += m_grav;
}