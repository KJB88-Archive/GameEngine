#include "GameScene.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

GameScene::GameScene()
	: Scene(0, "Game Scene")
{
	//printf("SCENE: GameObject with name %s, exists at position %f, %f %f with a Component with name %s",
	//	objects[0]->name.c_str(), 
	//	objects[0]->transform->position.x, 
	//	objects[0]->transform->position.y, 
	//	objects[0]->transform->position.z, 
	//	objects[0]->GetComponent("Test")->GetName().c_str())

	Entity* newEntity = new Entity(0, "New Entity");
	newEntity->AddComponent(new TransformComponent(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, 0.0f)));
	newEntity->AddComponent(new RenderComponent()); // TODO

	AddEntity(newEntity);

	printf("SCENE: Entity with name %s",
		entities[0]->name.c_str());
}

GameScene::~GameScene()
{


}

bool GameScene::RunScene()
{
	return Scene::RunScene(); 

	// Return false to continue game loop
}