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
	scenes = std::queue<Scene*>();
}

Scene* SceneManager::GetCurrentScene()
{
	return scenes.front();
}

void SceneManager::PopScene()
{
	scenes.pop();
}

void SceneManager::PushScene(Scene* newScene)
{
	scenes.push(newScene);
}

void SceneManager::RunScene()
{
	scenes.front()->RunScene();
}