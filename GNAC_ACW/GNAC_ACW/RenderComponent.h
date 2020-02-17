#pragma once
#include "IComponent.h"
#include "DXMesh.h"
#include "Graphics.h"

class RenderComponent : public IComponent
{
public:
	RenderComponent();
	virtual ~RenderComponent();

	// Inherited via IComponent
	virtual ComponentTypes ComponentType() override;

	DXMesh* mesh;

	//void Draw();

private:

	// TEMP SINGLE
	Graphics* gm;

	// TODO - Replace with generic wrappers
	//DXShader* shader;
};