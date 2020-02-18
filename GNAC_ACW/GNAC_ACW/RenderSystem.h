#pragma once
#include "ISystem.h"
class Graphics;


class RenderSystem 
	: public ISystem
{
public:
		RenderSystem(Graphics* graphics);
	virtual ~RenderSystem();

	// Inherited via ISystem
	virtual void ProcessEntities(std::vector<Entity*> entities) override;

private:

	const IComponent::ComponentTypes MASK =
		(IComponent::COMPONENT_RENDER);

		// Ref to renderer
		Graphics* graphics;

	RenderSystem(const RenderSystem& other);
};