#include "SceneManager.h"

SceneManager::SceneManager()
	: Manager("Scene")
{
}

SceneManager::~SceneManager()
{

}

void SceneManager::InitializeCoreResources()
{
	scenes = std::stack<Scene*>();
}

Scene* SceneManager::GetCurrentScene()
{
	return scenes.top();
}

void SceneManager::PopScene()
{
	scenes.pop();
}

void SceneManager::PushScene(Scene* newScene)
{
	scenes.push(newScene);
}

bool SceneManager::RunScene()
{
	if (scenes.size() > 0)
	{
		return scenes.top()->RunScene();
	}

	// If we have no scenes, 
	// let Game know that the application is basically finished
	return true;
}