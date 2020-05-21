#include "GameScene.h"

// Management
#include "SystemManager.h"
#include "Logger.h"

// Game Objects
#include "TestObject.h"
#include "GroundPlane.h"
#include "Sphere.h"

GameScene::GameScene(int id, Camera* mainCam, SceneManager* sm)
	: Scene(id, "Game Scene", mainCam, sm)
{
	// Add Systems
	systems.emplace_back(SystemManager::GetSystem("Physics"));
	systems.emplace_back(SystemManager::GetSystem("Collision"));
	systems.emplace_back(SystemManager::GetSystem("Render"));

	//// Add Entities
	//TestObject* square = new TestObject(entities.size());
	//entities.emplace_back(square);

	GroundPlane* gp = new GroundPlane(entities.size(), Vector3(1.0f, 1.0f, 1.0f));
	entities.emplace_back(gp);

	Sphere* s = new Sphere(entities.size(), Vector3(0.0f, 20.0f, 0.0f));
	entities.emplace_back(s);
}

GameScene::~GameScene()
{

}

bool GameScene::RunScene()
{
	for (int i = 0; i < systems.size(); ++i)
	{
		systems[i]->ProcessEntities(entities);
	}

	return false; // Return false to continue game loop

}