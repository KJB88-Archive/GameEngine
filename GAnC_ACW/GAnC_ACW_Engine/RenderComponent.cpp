#include "RenderComponent.h"

RenderComponent::RenderComponent(Entity* owner) 
	: Component(COMPONENT_RENDER, owner)
{
	// TODO
	mesh = new Mesh(0, "Mesh");
}

RenderComponent::~RenderComponent()
{

}