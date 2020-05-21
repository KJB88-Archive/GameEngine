#include "CollisionManager.h"
#include "CollisionSystem.h"

#include <iostream>

CollisionManager::CollisionManager()
	: Manager("Collision"), m_coeffOfRestitution(0.95f)
{
	m_collisionSystem = new CollisionSystem(this);
}

CollisionManager::~CollisionManager()
{
	delete m_collisionSystem;
	m_collisionSystem = nullptr;
}

CollisionSystem* CollisionManager::GetSystem()
{
	return m_collisionSystem;
}

bool CollisionManager::SphereToSphereDetection(Vector3& pos1, float& r1, Vector3& pos2, float& r2)
{
	Vector3 dist = Vector3(pos1.x - pos2.x, pos1.y - pos2.y, pos1.z - pos2.z);

	float distance = dist.Magnitude();

	if (distance < r1 + r2)
	{
		// Collision detected!
		return true;
	}

	return false;
}

bool CollisionManager::PlaneToSphereDetection(float& posY, Vector3& sPos, float& sRadius)
{
	// Very basic collision detection
	if (sPos.y + sRadius < posY)
	{
		// Collision detected!
		return true;
	}

	return false;
}

void CollisionManager::SphereToPlaneResponse(Vector3& vel, Vector3& norm)
{
	vel = Vector3(vel.x, -vel.y, vel.z) * 0.95f;

	//Vector3 newVec;
	//newVec = vel - (1 + m_coeffOfRestitution);

	//Vector3 collisionNormal = Vector3::Normalize(vel);
	//collisionNormal = collisionNormal * norm;

	//Vector3 finalVec = newVec * collisionNormal;

	//vel = finalVec;

	//Vector3 vn = Vector3::Normalize(vel);
	//vn = (vn * (1 + m_coeffOfRestitution));

	//Vector3 newVel = vel - (vn * norm);

	//vel = newVel;
	//Vector3 newVel = vel - (1 + 0.95f) 
}