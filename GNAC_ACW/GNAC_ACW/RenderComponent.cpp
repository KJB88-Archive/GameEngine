#include "RenderComponent.h"
#include "GraphicsManager.h"

RenderComponent::RenderComponent() 
	: IComponent(COMPONENT_RENDER)
{
	// Temp single
	gm = gm->instance;

	mesh = new DXMesh(gm->GetRenderer()->GetDevice());
}

RenderComponent::~RenderComponent()
{

}

IComponent::ComponentTypes RenderComponent::ComponentType()
{
	return componentType;
}

void RenderComponent::Draw()
{
	gm->Draw(mesh);
}
