#include "GameScene.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

GameScene::GameScene()
	: Scene(0, "Game Scene")
{
	Entity* newEntity = new Entity(0, "New Entity");
	newEntity->AddComponent(new TransformComponent(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), newEntity));
	newEntity->AddComponent(new RenderComponent(newEntity)); // TODO

	AddEntity(newEntity);

	Logger::LogToConsole("SCENE: Entity with name " + newEntity->name);
}

GameScene::~GameScene()
{

}

bool GameScene::RunScene()
{
	return Scene::RunScene(); 
	
	// Return false to continue game loop
}