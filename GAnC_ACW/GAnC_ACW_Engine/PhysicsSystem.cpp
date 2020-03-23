#include "PhysicsSystem.h"

// Targets
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

PhysicsSystem::PhysicsSystem()
	: ISystem(PHYSICS)
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
		std::vector<Component*> components = entities[i]->GetComponents();

		// Loop through components
		for (int j = 0; i < components.size(); ++j)
		{
			// Check to see if those components are the types we need
			if (components[j]->ComponentType() == MASK)
			{
				// Determine which component we're looking at
				switch (components[j]->ComponentType())
				{
				
					// Store our Physics component
				case Component::COMPONENT_PHYSICS:
					physics = dynamic_cast<PhysicsComponent*>(components[j]);
					break;

					// Store our Transform component
				case Component::COMPONENT_TRANSFORM:
					transform = dynamic_cast<TransformComponent*>(components[j]);
					break;
				}
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
