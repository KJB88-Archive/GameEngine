#include "Scene.h"
#include "SceneManager.h"

Scene::Scene(const int id, const std::string& name, SceneManager* sm)
	: id(id), name(name), sceneManager(sm)
{
	Logger::LogToConsole("SCENE: " + name + " created.");
}

Scene::~Scene()
{
	entities.clear();
	systems.clear();
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

void Scene::AddSystem(std::string systemName)
{
	BaseSystem* sys = SystemManager::GetSystem(systemName);

	if (sys != nullptr)
	{
		systems.emplace_back(sys);
	}
	else
	{
		Logger::LogToConsole("SCENE: Error adding manager to scene: " + systemName);
	}
}

void Scene::AddSystem(BaseSystem::SystemType systemType)
{
	BaseSystem* sys = SystemManager::GetSystem(systemType);

	if (sys != nullptr)
	{
		systems.emplace_back(sys);
	}
	else
	{
		Logger::LogToConsole("SCENE: Error adding manager to scene via type.");
	}
}

void Scene::RemoveSystem(std::string systemName)
{
	for (int i = 0; i < systems.size(); ++i)
	{
		if (systems[i]->GetName() == systemName)
		{
			systems.erase(systems.begin() + i);
		}
	}
}

void Scene::RemoveSystem(BaseSystem::SystemType systemType)
{
	for (int i = 0; i < systems.size(); ++i)
	{
		if (systems[i]->GetType() == systemType)
		{
			systems.erase(systems.begin() + i);
		}
	}
}

