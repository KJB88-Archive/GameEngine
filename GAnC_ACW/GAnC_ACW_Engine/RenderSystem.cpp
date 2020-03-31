#include "Logger.h"

// Graphics
#include "RenderSystem.h"
#include "Renderer.h"
#include "DXRenderer.h"

// Targets
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "Entity.h"


RenderSystem::RenderSystem(Renderer* renderer)
	: BaseSystem("Render", RENDER), renderer(renderer)
{
}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::ProcessEntities(std::vector<Entity*> entities)
{
	// Setup scene for rendering
	renderer->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		RenderComponent* render = NULL;
		TransformComponent* transform = NULL;

		// Get list of components attached to this entity
		std::vector<BaseComponent*> components = entities[i]->GetComponents();

		// Loop through components
		for (int j = 0; j < components.size(); ++j)
		{
			// Determine which component we're looking at
			switch (components[j]->ComponentType())
			{

				// Store our render component
			case BaseComponent::COMPONENT_RENDER:
				render = (RenderComponent*)components[j];
				break;

				// Store our transform component
			case BaseComponent::COMPONENT_TRANSFORM:
				transform = (TransformComponent*)components[j];
				break;
			}

			// Break out early if we have required components
			if (render && transform)
			{
				break;
			}
		}

		// Render the entity using it's component
		if (render && transform)
		{
			// TODO - Check for isVisible
			if (render->mesh) // Does this component have a mesh?
			{
				if (!render->mesh->GetVBO()) // Does the mesh have a valid VBO?
				{
					Logger::LogToConsole("RENDER SYSTEM: Object does not have a VBO, creating VBO...");
					render->mesh->CreateVBO(renderer); // Create VBO
				}

				// Draw (send transform values to do translation, rotation and scaling)
				renderer->Draw(
					transform->position, 
					transform->rotation, 
					transform->scale, 
					render->mesh);
			}

		}
	}

	// Finish scene setup for rendering
	renderer->EndScene();
}
