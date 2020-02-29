#include "RenderSystem.h"
#include "Renderer.h"
#include "RenderComponent.h"
#include "Entity.h"
#include "DXRenderer.h"

RenderSystem::RenderSystem(Renderer* renderer)
	: ISystem(RENDER), renderer(renderer)
{
}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::ProcessEntities(std::vector<Entity*> entities)
{
	// Loop through entities
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

		DXRenderer* dxRenderer = (DXRenderer*)renderer;
		dxRenderer->TestDraw();

		// Render the entity using it's component
		if (render)
		{

			// TODO - Check for isVisible
			if (render->mesh) // Does this component have a mesh?
			{
				if (!render->mesh->GetVBO()) // Does the mesh have a valid VBO?
				{
					render->mesh->CreateVBO(renderer); // Create VBO
				}

				render->mesh->GetVBO()->Draw(renderer); // Draw
			}

		}
	}
}
