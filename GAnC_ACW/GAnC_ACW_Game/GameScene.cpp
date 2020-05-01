#include "GameScene.h"
#include "SystemManager.h"
#include "Components.h"
#include "Logger.h"

GameScene::GameScene(int id, Camera* mainCam, SceneManager* sm)
	: Scene(id, "Game Scene", mainCam, sm)
{
	// Add Systems
	//systems.emplace_back(SystemManager::GetSystem("Physics"));
	systems.emplace_back(SystemManager::GetSystem("Render"));

	// Add Entities
	square = new Entity(entities.size(), "TestEntity");
	TransformComponent* tc = new TransformComponent(square);
	tc->position = Vector3(0.0f, 0.0f, 1.0f);
	square->AddComponent(tc);
	square->AddComponent(new RenderComponent(square));

	entities.emplace_back(square);
}

GameScene::~GameScene()
{
	delete square;
	square = nullptr;
}

bool GameScene::RunScene()
{
	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->ProcessEntities(entities);
	}

	return false; // Return false to continue game loop

}