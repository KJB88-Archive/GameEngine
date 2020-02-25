#include "RenderComponent.h"
#include "Graphics.h"

RenderComponent::RenderComponent() 
	: IComponent(COMPONENT_RENDER)
{
	mesh = new Mesh(0, "Mesh");

	// TODO
}

RenderComponent::~RenderComponent()
{

}

IComponent::ComponentTypes RenderComponent::ComponentType()
{
	return componentType;
}