#pragma once
#include <vector>
#include <string>
#include "GameObject.h"

class Scene
{
public:

	Scene(const std::string& name);
	virtual ~Scene();

	virtual void Update() = 0;
	virtual void Render() = 0;

	const std::string& GetName();

	void AddGameObject(GameObject* go);
	void RemoveGameObject(const std::string& objName);

protected:
	std::vector<GameObject*> objects;

private:

	const std::string& name;
	void InitializeCoreResources();
};