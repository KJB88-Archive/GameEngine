#include "TestGame.h"
#include "GameScene.h"

TestGame::TestGame()
	: Game()
{
}

TestGame::~TestGame()
{

}

void TestGame::Initialise()
{
	// Add systems to SystemManager (order is important)
	SystemManager::AddSystem(engine()->physicsManager()->GetSystem());
	SystemManager::AddSystem(engine()->collisionManager()->GetSystem());
	SystemManager::AddSystem(engine()->renderer()->GetSystem());

	// Scene construction
	engine()->sceneManager()->PushScene(
		new GameScene(0, engine()->renderer()->GetMainCam(), engine()->sceneManager()));
}

bool TestGame::Run()
{
	return engine()->sceneManager()->RunScene();
}

void TestGame::Reset()
{
	// TODO
}