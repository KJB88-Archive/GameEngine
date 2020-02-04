#include "Entity.h"

Entity::Entity(int id, const std::string& name)
	: id(id), name(name)
{
	components = std::vector<IComponent*>();

	printf("GAMEOBJECT: %i:%s created.\n", id, name.c_str());
}

Entity::~Entity()
{
	components.clear();
}

IComponent* const Entity::GetComponent(const IComponent::ComponentTypes componentType)
{
	for (int i = 0; i < components.size(); ++i)
	{
		if (components[i]->ComponentType() == componentType)
		{

			return components[i];
		}
	}
}

void Entity::AddComponent(IComponent* component)
{
	components.push_back(component);
}