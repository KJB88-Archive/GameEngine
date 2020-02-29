#pragma once
#include "Manager.h"
#include "Scene.h"

#include <stack>

class SceneManager
	: Manager
{
public:

	SceneManager();
	virtual ~SceneManager();

	void PopScene();
	void PushScene(Scene* newScene);
	Scene* GetCurrentScene();

	bool RunScene();

private:

	std::stack<Scene*> scenes;

	void InitializeCoreResources();

	SceneManager(const SceneManager&) = delete;
	SceneManager* operator=(const SceneManager&) = delete;
};