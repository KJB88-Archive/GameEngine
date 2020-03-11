#include "Scene.h"

Scene::Scene(const int id, const std::string& name)
	: id(id), name(name)
{
	InitializeCoreResources();

	Logger::LogToConsole("SCENE: " + name + " created.");
}

Scene::~Scene()
{
	entities.clear();
	systems.clear();
}

bool Scene::RunScene()
{
	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->ProcessEntities(entities);
	}

	return false; // Return false to continue game loop
}

void Scene::InitializeCoreResources()
{
	entities = std::vector<Entity*>();
	systems = std::vector<ISystem*>();
}

const std::string& Scene::GetName()
{
	return name;
}

const int Scene::GetID()
{
	return id;
}

void Scene::AddSystem(ISystem* system)
{
	systems.emplace_back(system);
}

void Scene::RemoveSystem(ISystem::SystemType type)
{
	for (int i = 0; i < systems.size(); ++i)
	{
		if (systems[i]->GetType() == type)
		{
			systems.erase(systems.begin() + i);
		}
	}
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

