#include "GameObject.h"

GameObject::GameObject()
	: name("NO NAME"), tag("NO TAG")
{
	InitializeCoreResources();

	printf("GameObject: %s created.\n", name.c_str());
}

GameObject::GameObject(const std::string& name)
	: name(name), tag("NO TAG")
{
	InitializeCoreResources();

	printf("GameObject: %s created.\n", name.c_str());
}

GameObject::GameObject(const std::string& name, const std::string& tag)
	: name(name), tag(tag)
{
	InitializeCoreResources();

	printf("GameObject: %s created.\n", name.c_str());
}

GameObject::~GameObject()
{
	delete transform;
	transform = NULL;

	components.clear();
}

void GameObject::Initialize()
{
	// STUB
}

void GameObject::Update()
{
	// STUB
}

void GameObject::Render()
{
	// STUB
}

Component& GameObject::GetComponent(const std::string& componentName)
{
	for (int i = 0; i < components.size(); ++i)
	{
		if (components[i].GetName() == componentName)
		{
			return components[i];
		}
	}
}

void GameObject::AddComponent(Component component)
{
	components.emplace_back(&component);
}

void GameObject::InitializeCoreResources()
{
	transform = new Transform();
	components = std::vector<Component>();
}