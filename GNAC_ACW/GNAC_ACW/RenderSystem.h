#pragma once
#include "ISystem.h"

#include "GraphicsManager.h"

class RenderSystem : ISystem
{
public:
	RenderSystem(GraphicsManager* gm);
	virtual ~RenderSystem();

	// Inherited via ISystem
	virtual void ProcessEntities(std::vector<Entity*> entities) override;
	virtual SystemType GetType() override;

private:

	const IComponent::ComponentTypes MASK =
		(IComponent::COMPONENT_RENDER | IComponent::COMPONENT_TRANSFORM);

		// Ref to abstracted renderer
		GraphicsManager* gm;

	RenderSystem(const RenderSystem& other);
};