#include "CollisionSystem.h"
#include "CollisionManager.h"

// Components
#include "TransformComponent.h"
#include "ColliderSphereComponent.h"
#include "ColliderPlaneComponent.h"
#include "PhysicsComponent.h"

CollisionSystem::CollisionSystem(CollisionManager* collisionManager)
	: BaseSystem("Collision", SystemType::COLLISION), m_collisionManager(collisionManager)
{

}

CollisionSystem::~CollisionSystem()
{

}

void CollisionSystem::ProcessEntities(std::vector<Entity*> entities)
{
	// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		TransformComponent* transform = NULL;
		PhysicsComponent* physics = NULL;
		BaseColliderComponent* collider = NULL;

		// GET COMPONENTS
		// Get list of components attached to this entity
		std::vector<BaseComponent*> components = entities[i]->GetComponents();

		// Loop through components
		for (int j = 0; j < components.size(); ++j)
		{
			// Determine which component we're looking at
			switch (components[j]->GetType())
			{
				// Store our render component
			case BaseComponent::COMPONENT_COLLIDER:
				collider = (BaseColliderComponent*)components[j];
				break;

				// Store our transform component
			case BaseComponent::COMPONENT_PHYSICS:
				physics = (PhysicsComponent*)components[j];
				break;

				// Store our transform component
			case BaseComponent::COMPONENT_TRANSFORM:
				transform = (TransformComponent*)components[j];
				break;
			}
			// Break out early if we have required components
			if (transform && physics && collider)
			{
				break;
			}
		}

		// If any required component was not found,
		// continue to next entity
		if (collider == NULL || transform == NULL || physics == NULL)
		{
			continue;
		}

		switch (collider->colliderType)
		{
		case BaseColliderComponent::ColliderType::SPHERE:
			ColliderSphereComponent* csc =
				(ColliderSphereComponent*)collider;

			float posY = 1.0f;
			if (m_collisionManager->PlaneToSphereDetection(posY, transform->position, csc->radius))
			{
				Vector3 n = Vector3(0.0f, 1.0f, 0.0f);
				m_collisionManager->SphereToPlaneResponse(physics->velocity, n);
			}

			//if ((transform->position.y - csc->radius) <= 0.0f)
			//{
			//	transform->position.y = 20.0f;
			//}

			break;
		}
	}
}