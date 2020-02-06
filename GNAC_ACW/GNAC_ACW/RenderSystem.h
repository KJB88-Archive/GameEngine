#pragma once
#include "GraphicsManager.h"

class RenderSystem
{
public:
	RenderSystem(GraphicsManager* gm);
	~RenderSystem();


private:

	// Ref to abstracted renderer
	GraphicsManager* gm;

	RenderSystem(const RenderSystem& other);
};