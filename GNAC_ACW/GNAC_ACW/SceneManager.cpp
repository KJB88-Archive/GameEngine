#include "SceneManager.h"
#include "GameScene.h"

SceneManager::SceneManager()
	: Manager("Scene Manager")
{
	PushScene(new GameScene());
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