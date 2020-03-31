#pragma once
#include <vector>

#include "BaseComponent.h"
#include "Components.h"

class Entity
{

public:

	Entity(int id, const std::string& name);
	virtual ~Entity();

	const int id;
	std::string name;

	BaseComponent* const GetComponent(const BaseComponent::ComponentType componentType);
	std::vector<BaseComponent*> GetComponents();
	void AddComponent(BaseComponent* component);

private:
	// Component container
	std::vector<BaseComponent*> components;

	Entity(const Entity& other) = delete;

};