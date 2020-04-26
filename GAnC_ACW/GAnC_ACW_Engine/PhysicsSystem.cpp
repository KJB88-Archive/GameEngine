#include "PhysicsSystem.h"

// Targets
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

PhysicsSystem::PhysicsSystem(PhysicsManager* physics)
	: BaseSystem("Physics", PHYSICS), m_physics(physics)
{

}

PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::ProcessEntities(std::vector<Entity*> entities)
{
	// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		PhysicsComponent* physics = NULL;
		TransformComponent* transform = NULL;

		// get list of components attached to this entity
		std::vector<BaseComponent*> components = entities[i]->GetComponents();

		// Loop through components
		for (int j = 0; j < components.size(); ++j)
		{
			// Determine which component we're looking at
			switch (components[j]->GetType())
			{

				// Store our Physics component
			case BaseComponent::COMPONENT_PHYSICS:
				physics = dynamic_cast<PhysicsComponent*>(components[j]);
				break;

				// Store our Transform component
			case BaseComponent::COMPONENT_TRANSFORM:
				transform = dynamic_cast<TransformComponent*>(components[j]);
				break;
			}

			// Break out early if we have required components
			if (physics && transform)
			{
				break;
			}
		}

		if (physics)
		{
			// TODO - Check for isResting
			transform->position.x++;
		}
	}
}
