#include "SceneManager.h"
#include "GameScene.h"

SceneManager::SceneManager()
	: Manager("Scene Manager")
{
	GameScene* newScene = new GameScene();
	newScene->Initialize();

	PushScene(newScene);
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

void SceneManager::UpdateScene(float deltaTime)
{
	scenes.front()->Update(deltaTime);
}

void SceneManager::RenderScene(RenderSystem* renderSystem)
{
	GetCurrentScene()->Render(renderSystem);
}