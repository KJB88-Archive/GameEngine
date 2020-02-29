#include "RenderComponent.h"

RenderComponent::RenderComponent() 
	: IComponent(COMPONENT_RENDER)
{
	// TODO
	mesh = new Mesh(0, "Mesh");
}

RenderComponent::~RenderComponent()
{

}

IComponent::ComponentTypes RenderComponent::ComponentType()
{
	return componentType;
}