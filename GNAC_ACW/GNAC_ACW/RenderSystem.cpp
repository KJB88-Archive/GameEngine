#include "RenderSystem.h"

#include "RenderComponent.h"

RenderSystem::RenderSystem(GraphicsManager* gm)
	: ISystem(SYSTEM_RENDER), gm(gm)
{
	gm = gm->instance;
}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::ProcessEntities(std::vector<Entity*> entities)
{
	RenderComponent* render = NULL;

	//// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		std::vector<IComponent*> components = entities[i]->GetComponents();

		for (int j = 0; j < components.size(); ++j)
		{
			// Check to see if those components are the types we need
			if (components[j]->ComponentType() == MASK)
			{
				render = (RenderComponent*)components[j];
			}
		}

		// Render Entity
		if (render)
		{

			// TODO - Check for isVisible
			if (render->mesh)
			{
				gm->Draw(render->mesh);
			}

		}
	}
}

ISystem::SystemType RenderSystem::GetType()
{
	return systemType;
}
