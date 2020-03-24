#pragma once
#include "ISystem.h"
class Renderer;

class RenderSystem
	: public ISystem
{
public:
	RenderSystem(Renderer* renderer);
	virtual ~RenderSystem();

	// Inherited via ISystem
	virtual void ProcessEntities(std::vector<Entity*> entities) override;

private:

	// Ref to renderer
	Renderer* renderer;

	RenderSystem(const RenderSystem& other);
};