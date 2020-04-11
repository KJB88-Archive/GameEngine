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
	// Add systems to SystemManager
	SystemManager::AddSystem(engine()->physicsManager()->GetSystem());
	SystemManager::AddSystem(engine()->renderer()->GetSystem());

	// Scene construction
	engine()->sceneManager()->PushScene(new GameScene(0, engine()->sceneManager()));
}

bool TestGame::Run()
{
	return engine()->sceneManager()->RunScene();
}

void TestGame::Reset()
{
	// TODO
}