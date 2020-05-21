#pragma once
#include"Manager.h"
#include "Vector3.h"
#include "CollisionSystem.h"


class CollisionManager
	: public Manager
{
public:
	CollisionManager();
	virtual ~CollisionManager();

	CollisionSystem* GetSystem();

	bool SphereToSphereDetection(Vector3& pos1, float& r1, Vector3& pos2, float& r2);
	bool PlaneToSphereDetection(float& posY, Vector3& sPos, float& sRadius);

	//void SphereToSphereResponse();
	void SphereToPlaneResponse(Vector3& vel, Vector3& norm);

private:

	const float m_coeffOfRestitution;

	CollisionSystem* m_collisionSystem;
};