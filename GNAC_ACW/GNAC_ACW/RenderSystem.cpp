#include "RenderSystem.h"

#include "RenderComponent.h"

RenderSystem::RenderSystem(Graphics* gm)
	: ISystem(RENDER), graphics(graphics)
{
	gm = gm->instance;
}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::ProcessEntities(std::vector<Entity*> entities)
{

	//// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		RenderComponent* render = NULL;

		// Get list of components attached to this entity
		std::vector<IComponent*> components = entities[i]->GetComponents();

		// Loop through components
		for (int j = 0; j < components.size(); ++j)
		{
			// Check to see if those components are the types we need
			if (components[j]->ComponentType() == MASK)
			{
				// Store our render component
				render = (RenderComponent*)components[j];
			}
		}

		// Render the entity using it's component
		if (render)
		{

			// TODO - Check for isVisible
			if (render->mesh)
			{
				graphics->Draw(render->mesh);
			}

		}
	}
}
