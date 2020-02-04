#pragma once
#include <vector>

#include "IComponent.h"
#include "GraphicsManager.h"
class Entity
{

public:

	Entity(int id, const std::string& name);
	virtual ~Entity();

	const int id;
	std::string name;

	IComponent* const GetComponent(const IComponent::ComponentTypes componentType);
	void AddComponent(IComponent* component);

private:

	// Component container
	std::vector<IComponent*> components;

	Entity(const Entity& other);
};