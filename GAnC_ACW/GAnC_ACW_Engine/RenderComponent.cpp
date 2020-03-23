#include "RenderComponent.h"

RenderComponent::RenderComponent(Entity* owner) 
	: Component(COMPONENT_RENDER, owner)
{
	mesh = new Mesh();
}

RenderComponent::~RenderComponent()
{

}