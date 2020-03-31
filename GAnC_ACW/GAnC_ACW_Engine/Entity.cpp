#include "Entity.h"
#include "RenderComponent.h"
#include "Logger.h"

Entity::Entity(int id, const std::string& name)
	: id(id), name(name)
{
	Logger::LogToConsole("GAMEOBJECT: " + name + " created.");
}

Entity::~Entity()
{
	components.clear();
}

BaseComponent* const Entity::GetComponent(const BaseComponent::ComponentType componentType)
{
	for (int i = 0; i < (int)components.size(); i++)
	{
		if (components[i]->GetType() == componentType)
		{

			return components[i];
		}
	}
}

std::vector<BaseComponent*> Entity::GetComponents()
{
	return components;
}

void Entity::AddComponent(BaseComponent* component)
{
	components.push_back(component);
}