#include "PhysicsManager.h"
#include "TimeManager.h"
#include "PhysicsSystem.h"

PhysicsManager::PhysicsManager()
	: Manager("Physics")
{
	m_physicsSystem = new PhysicsSystem(this);
}

PhysicsManager::~PhysicsManager()
{

}

Vector3 PhysicsManager::CalculateNewPositions(Vector3 pos)
{
	pos.x += TimeManager::GetDeltaTime();

	return pos;
}

PhysicsSystem* PhysicsManager::GetSystem()
{
	return m_physicsSystem;
}