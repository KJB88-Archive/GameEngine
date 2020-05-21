#pragma once
#include <vector>
#include <string>

#include "Entity.h"
#include "BaseSystem.h"
#include "Logger.h"
#include "SystemManager.h"
#include "Camera.h"

class SceneManager;

class Scene
{
public:

	Scene(const int id, const std::string& name, Camera* mainCam, SceneManager* sm);
	virtual ~Scene();

	virtual bool RunScene() = 0;

	const int GetID();
	const std::string& GetName();


	// ENTITY MANIPULATION
	// Add entity via ptr
	void AddEntity(Entity* go);

	// Remove entity via name
	void RemoveEntity(const std::string& objName);

	// Remove entity via int
	void RemoveEntity(const int id);

	// SYSTEM MANIPULATION
	// Add system via name
	void AddSystem(std::string systemName);

	// Add system via type
	void AddSystem(BaseSystem::SystemType systemType);
	
	// Remove system via nam
	void RemoveSystem(std::string systemName);
	void RemoveSystem(BaseSystem::SystemType systemType);

	void Reset();
protected:

	// Main camera for scene
	Camera* m_mainCam;

	// Entity container
	std::vector<Entity*> entities;

	// System container
	std::vector<BaseSystem*> systems;

private:

	// Int Identifier
	const int id;

	// String identifier
	const std::string& name;

	// Reference to SM for Scene switching
	const SceneManager* sceneManager;
};