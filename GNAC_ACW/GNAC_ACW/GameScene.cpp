#include "GameScene.h"

GameScene::GameScene()
	: Scene("Game Scene")
{
	//AddGameObject(new TestObject("New GameObject"));

	//printf("SCENE: GameObject with name %s, exists at position %f, %f %f with a Component with name %s",
	//	objects[0]->name.c_str(), 
	//	objects[0]->transform->position.x, 
	//	objects[0]->transform->position.y, 
	//	objects[0]->transform->position.z, 
	//	objects[0]->GetComponent("Test")->GetName().c_str());
}

GameScene::~GameScene()
{

}

void GameScene::Initialize()
{

}

void GameScene::Update(float deltaTime)
{

}

void GameScene::Render()
{

}