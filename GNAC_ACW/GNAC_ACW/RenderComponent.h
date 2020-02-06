#pragma once
#include "IComponent.h"
#include "DXMesh.h"
#include "GraphicsManager.h"

class RenderComponent : public IComponent
{
public:
	RenderComponent();
	virtual ~RenderComponent();

	// Inherited via IComponent
	virtual ComponentTypes ComponentType() override;

	DXMesh* mesh;

	void Draw();

private:

	// TEMP SINGLE
	GraphicsManager* gm;

	// TODO - Replace with generic wrappers
	//DXShader* shader;
};