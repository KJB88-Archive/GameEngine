#pragma once
#include "IComponent.h"
#include "DXShader.h"
#include "DXMesh.h"

class RenderComponent : public IComponent
{
public:
	RenderComponent();
	virtual ~RenderComponent();

	// Inherited via IComponent
	virtual ComponentTypes ComponentType() override;

private:

	// TODO - Replace with generic wrappers
	DXMesh* mesh;
	DXShader* shader;

	// Shader* shader;
	// Mesh* mesh;
	// Material* mat // colour, tex, normalmap, etc
};