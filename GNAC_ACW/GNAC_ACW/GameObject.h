#pragma once
#include <vector>

#include "Transform.h"
#include "Component.h"

class GameObject
{

public:

	GameObject();
	GameObject(const std::string& name);
	GameObject(const std::string& name, const std::string& tag);
	GameObject(const GameObject& other);
	virtual ~GameObject();

	std::string name;
	std::string tag;

	Transform* transform;

	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	Component* const GetComponent(const std::string& componentName);
	void AddComponent(Component* component);

private:

	// Component container
	std::vector<Component*> components;
	
	void InitializeCoreResources();
};