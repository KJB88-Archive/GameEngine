#pragma once
#include "Manager.h"
#include "Scene.h"

#include <queue>

class SceneManager
	: Manager
{
public:

	SceneManager();
	virtual ~SceneManager();

	void PopScene();
	void PushScene(Scene* newScene);
	Scene* GetCurrentScene();

	void UpdateCurrentScene();
	void RenderCurrentScene();

private:

	std::queue<Scene*> scenes;

	void InitializeCoreResources();

	SceneManager(const SceneManager&) = delete;
	SceneManager* operator=(const SceneManager&) = delete;
};