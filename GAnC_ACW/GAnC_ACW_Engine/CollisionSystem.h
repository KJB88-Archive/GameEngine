#pragma once
#include "BaseSystem.h"
#include <vector>

class CollisionManager;

class CollisionSystem
	: public BaseSystem
{
public:

	CollisionSystem(CollisionManager* collisionManager);
	virtual ~CollisionSystem();

	virtual void ProcessEntities(std::vector<Entity*> entities) override;

private:

	struct ManifoldEntry
	{
		Entity* e1;
		Entity* e2;
		Vector3 normal;
	};

	std::vector<ManifoldEntry*> m_manifold;

	CollisionManager* m_collisionManager;
};