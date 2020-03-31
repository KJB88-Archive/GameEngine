#pragma once
#include "BaseComponent.h"
#include "Mesh.h"

class RenderComponent 
	: public BaseComponent
{
public:
	RenderComponent(Entity* owner);
	virtual ~RenderComponent();

	Mesh* mesh;

private:

};