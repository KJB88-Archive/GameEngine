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
	std::vector<IComponent*> GetComponents();
	void AddComponent(IComponent* component);

	void Draw();
private:

	// Component container
	std::vector<IComponent*> components;

	Entity(const Entity& other);

};