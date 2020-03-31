#include "RenderComponent.h"

RenderComponent::RenderComponent(Entity* owner) 
	: BaseComponent("Render", COMPONENT_RENDER, owner)
{
	mesh = new Mesh();
}

RenderComponent::~RenderComponent()
{

}