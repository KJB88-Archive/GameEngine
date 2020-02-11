#include "RenderSystem.h"

RenderSystem::RenderSystem(GraphicsManager* gm)
	: ISystem(SYSTEM_RENDER), gm(gm)
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::ProcessEntities(std::vector<Entity*> entities)
{
	//// Loop through entities
	for (int i = 0; i < entities.size; ++i)
	{
		std::vector<IComponent*> components = entities[i]->GetComponents();

		for (int j = 0; j < components.size; ++j)
		{
			// Check to see if those components are the types we need

			// Get component values

			// Render Entity
		}
	}



}

ISystem::SystemType RenderSystem::Type()
{
	return SystemType();
}
