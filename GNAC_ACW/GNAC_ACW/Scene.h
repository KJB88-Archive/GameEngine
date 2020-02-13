#pragma once
#include <vector>
#include <string>
#include "Entity.h"
#include "RenderSystem.h"

class Scene
{
public:

	Scene(const int id, const std::string& name);
	virtual ~Scene();

	virtual void Update(float deltaTime) = 0;
	virtual void Render(RenderSystem* renderer) = 0;

	const int GetID();
	const std::string& GetName();

	void AddEntity(Entity* go);
	void RemoveEntity(const std::string& objName);
	void RemoveEntity(const int id);

protected:
	std::vector<Entity*> entities;

private:

	const int id;
	const std::string& name;
	void InitializeCoreResources();
};