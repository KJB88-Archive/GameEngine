#include "RenderComponent.h"
#include "Graphics.h"

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