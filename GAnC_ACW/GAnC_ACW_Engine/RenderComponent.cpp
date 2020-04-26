#include "RenderComponent.h"
#include "AssetManager.h"

RenderComponent::RenderComponent(Entity* owner) 
	: BaseComponent("Render", COMPONENT_RENDER, owner)
{
	mesh = static_cast<Mesh*>(AssetManager::GetAsset("mesh_square.txt"));
}

RenderComponent::~RenderComponent()
{
	
}