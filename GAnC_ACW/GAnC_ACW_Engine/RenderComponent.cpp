#include "RenderComponent.h"
#include "Entity.h"

#include "AssetManager.h"
RenderComponent::RenderComponent(Entity* owner) 
	: BaseComponent("Render", COMPONENT_RENDER, owner)
{
	m_owner->AddComponent(this);
}

Mesh* RenderComponent::GetMesh()
{
	return mesh;
}

void RenderComponent::SetMesh(std::string fileName)
{
	mesh = (Mesh*)AssetManager::GetAsset(fileName);
}
RenderComponent::~RenderComponent()
{
	
}