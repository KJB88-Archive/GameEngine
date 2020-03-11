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
	GameScene* gameScene = new GameScene();
	gameScene->AddSystem(m_renderSystem);
	m_sceneManager->PushScene(gameScene);

}

bool TestGame::Run()
{
	Logger::LogToConsole(std::to_string(m_time->GetDeltaTime()));
	return Game::Run();
}

void TestGame::Reset()
{

}