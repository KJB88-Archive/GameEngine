#pragma once
#include <vector>
#include <string>
#include "Entity.h"
#include "ISystem.h"
#include "RenderSystem.h"
#include "Logger.h"

class Scene
{
public:

	Scene(const int id, const std::string& name);
	virtual ~Scene();

	virtual bool RunScene();

	const int GetID();
	const std::string& GetName();

	void AddSystem(ISystem* system);
	void RemoveSystem(ISystem::SystemType type);

	void AddEntity(Entity* go);
	void RemoveEntity(const std::string& objName);
	void RemoveEntity(const int id);

protected:
	std::vector<Entity*> entities;
	std::vector<ISystem*> systems;

private:

	void InitializeCoreResources();

	const int id;
	const std::string& name;
};