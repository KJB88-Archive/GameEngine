#pragma once
#include "Component.h"
#include "Mesh.h"

class RenderComponent 
	: public Component
{
public:
	RenderComponent(Entity* owner);
	virtual ~RenderComponent();

	Mesh* mesh;

private:

};