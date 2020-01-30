#include "Entity.h"

Entity::Entity(int id, const std::string& name)
	: id(id), name(name)
{
	components = std::vector<Component*>();

	printf("GAMEOBJECT: %i : %s created.\n", id, name.c_str());
}

Entity::~Entity()
{
	components.clear();
}

Component* const Entity::GetComponent(const std::string& componentName)
{
	for (int i = 0; i < components.size(); ++i)
	{
		if (components[i]->GetName() == componentName)
		{

			return components[i];
		}
	}
}

void Entity::AddComponent(Component* component)
{
	components.push_back(component);
}