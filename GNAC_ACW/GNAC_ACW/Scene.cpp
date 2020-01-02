#include "Scene.h"

Scene::Scene(const std::string& name)
	: name(name)
{
	InitializeCoreResources();

	printf("Scene created.\n");
}

Scene::~Scene()
{
	objects.clear();
}

void Scene::InitializeCoreResources()
{
	objects = std::vector<GameObject>();
}

const std::string& Scene::GetName()
{
	return name;
}

void Scene::AddGameObject(GameObject go)
{
	objects.emplace_back(go);
}

void Scene::RemoveGameObject(const std::string& objName)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i].name == objName)
		{
			objects.erase(objects.begin() + i);
		}
	}
}

