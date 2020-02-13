#include "Scene.h"

Scene::Scene(const int id, const std::string& name)
	: id(id), name(name)
{
	InitializeCoreResources();

	printf("SCENE: %s created.\n", name.c_str());
}

Scene::~Scene()
{
	entities.clear();
}

void Scene::InitializeCoreResources()
{
	entities = std::vector<Entity*>();
}

const std::string& Scene::GetName()
{
	return name;
}

const int Scene::GetID()
{
	return id;
}

void Scene::AddEntity(Entity* go)
{
	entities.emplace_back(go);
}

void Scene::RemoveEntity(const std::string& objName)
{
	// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		// Check if the entity name is matched
		if (entities[i]->name == objName)
		{
			// Erase that entity
			entities.erase(entities.begin() + i);
		}
	}
}

void Scene::RemoveEntity(const int id)
{
	// Loop through entities
	for (int i = 0; i < entities.size(); ++i)
	{
		// Check if entity id is matched
		if (entities[i]->id == id)
		{
			// Erase that entity
			entities.erase(entities.begin() + i);
		}
	}
}
