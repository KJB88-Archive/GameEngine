#include "GameScene.h"
#include "SystemManager.h"
#include "Components.h"

#include "InputManager.h"

GameScene::GameScene(int id, SceneManager* sm)
	: Scene(id, "Game Scene", sm)
{

	// Add Systems
	systems.emplace_back(SystemManager::GetSystem("Physics"));
	systems.emplace_back(SystemManager::GetSystem("Render"));

	// Add Entities
	Entity* newEntity = new Entity(entities.size(), "TestEntity");
	newEntity->AddComponent(new TransformComponent(newEntity));
	newEntity->AddComponent(new RenderComponent(newEntity));

	entities.emplace_back(newEntity);
	
	Logger::LogToConsole("SCENE: System with name: Render");

}

GameScene::~GameScene()
{

}

bool GameScene::RunScene()
{
	if (InputManager::GetButtonDown("Jump"))
	{
	}

	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->ProcessEntities(entities);
	}

	return false; // Return false to continue game loop
	  
}