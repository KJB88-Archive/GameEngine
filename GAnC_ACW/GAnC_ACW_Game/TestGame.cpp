#include "TestGame.h"
#include "GameScene.h"

TestGame::TestGame()
	: Game()
{

}

TestGame::~TestGame()
{

}

void TestGame::Initialise(Window* wnd, Renderer* renderer)
{
	// Initialise base resources
	Game::Initialise(wnd, renderer);

	// Scene construction
	m_sceneManager->PushScene(new GameScene(0, m_sceneManager));

}

bool TestGame::Run()
{
	return Game::Run();
}

void TestGame::Reset()
{

}