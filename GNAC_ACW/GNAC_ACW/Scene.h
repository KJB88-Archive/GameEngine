#pragma once
#include <vector>
#include <string>
#include "Entity.h"

class Scene
{
public:

	Scene(const std::string& name);
	virtual ~Scene();

	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	const std::string& GetName();

	void AddGameObject(Entity* go);
	void RemoveGameObject(const std::string& objName);

protected:
	std::vector<Entity*> objects;

private:

	const std::string& name;
	void InitializeCoreResources();
};