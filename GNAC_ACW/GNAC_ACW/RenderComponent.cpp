#include "RenderComponent.h"
#include "Graphics.h"

RenderComponent::RenderComponent() 
	: IComponent(COMPONENT_RENDER)
{
	mesh = new DXMesh(Graphics::instance->GetRenderer()->GetDevice());
}

RenderComponent::~RenderComponent()
{

}

IComponent::ComponentTypes RenderComponent::ComponentType()
{
	return componentType;
}