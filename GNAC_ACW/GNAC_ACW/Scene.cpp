#include "Scene.h"

Scene::Scene(const std::string& name)
	: name(name)
{
	InitializeCoreResources();

	printf("SCENE: %s created.\n", name.c_str());
}

Scene::~Scene()
{
	objects.clear();
}

void Scene::InitializeCoreResources()
{
	objects = std::vector<GameObject*>();
}

const std::string& Scene::GetName()
{
	return name;
}

void Scene::AddGameObject(GameObject* go)
{
	objects.push_back(go);
}

void Scene::RemoveGameObject(const std::string& objName)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i]->name == objName)
		{
			objects.erase(objects.begin() + i);
		}
	}
}

