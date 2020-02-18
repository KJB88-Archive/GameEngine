#pragma once
#include "IComponent.h"
#include "DXMesh.h"
#include "Graphics.h"

class RenderComponent 
	: public IComponent
{
public:
	RenderComponent();
	virtual ~RenderComponent();

	// Inherited via IComponent
	virtual ComponentTypes ComponentType() override;

	DXMesh* mesh;

private:

};