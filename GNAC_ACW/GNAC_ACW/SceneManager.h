#pragma once
#include "Manager.h"
#include "Scene.h"

#include <queue>

// TEMP
#include "GraphicsManager.h"

class SceneManager
	: Manager
{
public:

	SceneManager();
	virtual ~SceneManager();

	void PopScene();
	void PushScene(Scene* newScene);
	Scene* GetCurrentScene();

	void UpdateScene(float deltaTime);
	void RenderScene(RenderSystem* renderSystem);

private:

	std::queue<Scene*> scenes;

	void InitializeCoreResources();

	SceneManager(const SceneManager&) = delete;
	SceneManager* operator=(const SceneManager&) = delete;
};