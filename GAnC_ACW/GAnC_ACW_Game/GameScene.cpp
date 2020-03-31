#include "GameScene.h"
#include "SystemManager.h"
#include "Components.h"

// Entities
#include "TestEntity.h"
GameScene::GameScene(int id, SceneManager* sm)
	: Scene(id, "Game Scene", sm)
{

	// Add Systems
	systems.emplace_back(SystemManager::GetSystem("Render"));
	systems.emplace_back(SystemManager::GetSystem("Physics"));

	// Add Entities
	entities.emplace_back(new TestEntity(entities.size(), "TestEntity"));

	Logger::LogToConsole("SCENE: System with name: Render");

}

GameScene::~GameScene()
{

}

bool GameScene::RunScene()
{
	return Scene::RunScene(); 
	
	// Return false to continue game loop
}