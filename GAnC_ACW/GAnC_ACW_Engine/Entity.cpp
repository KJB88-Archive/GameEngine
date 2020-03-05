#include "Entity.h"
#include "RenderComponent.h"

Entity::Entity(int id, const std::string& name)
	: id(id), name(name)
{
	components = std::vector<Component*>();

	printf("GAMEOBJECT: %i:%s created.\n", id, name.c_str());
}

Entity::~Entity()
{
	components.clear();
}

Component* const Entity::GetComponent(const Component::ComponentTypes componentType)
{
	for (int i = 0; i < (int)components.size(); i++)
	{
		if (components[i]->ComponentType() == componentType)
		{

			return components[i];
		}
	}
}

std::vector<Component*> Entity::GetComponents()
{
	return components;
}

void Entity::AddComponent(Component* component)
{
	components.push_back(component);
}

//void Entity::Draw()
//{
//	RenderComponent* rc = (RenderComponent*)GetComponent(IComponent::COMPONENT_RENDER);
//	rc->Draw();
//}