#include "Game.h"

Game::Game()
	: m_input(nullptr), m_renderer(nullptr), m_time(nullptr), m_sceneManager(nullptr)
{
	// Create Time Manager
	m_time = new Time();
	if (!m_time)
	{
		printf("GAME: Unable to create TimeManager object.\n");
	}

	// Create Input Manager
	m_input = new Input();
	if (!m_input)
	{
		printf("GAME: Unable to create InputManager object.\n");
	}

	// Create Scene Manager
	m_sceneManager = new SceneManager();
	if (!m_sceneManager)
	{
		printf("GAME: Unable to create SceneManager object.\n");
	}

	// Create systems
	CreateSystems();
}

Game::~Game()
{
	if (m_time)
	{
		delete m_time;
		m_time = nullptr;
	}

	if (m_renderer)
	{
		delete m_renderer;
		m_renderer = nullptr;
	}

	if (m_input)
	{
		delete m_input;
		m_input = nullptr;
	}

	if (m_sceneManager)
	{
		delete m_sceneManager;
		m_sceneManager = nullptr;
	}

	if (m_window)
	{
		delete m_window;
		m_window = nullptr;
	}

}

void Game::Initialise(Window* window, Renderer* renderer)
{
	m_renderer = renderer;
	m_window = window;
}

void Game::CreateSystems()
{
// Create Render System
	m_renderSystem = new RenderSystem(m_renderer);
	if (!m_renderSystem)
	{
		printf("GAME: Unable to create RenderSystem object.\n");
	}
}

void Game::Run()
{
	m_time->Update();

	m_sceneManager->RunScene(); // Main update call
}

void Game::OnKeyboard(int key, bool down)
{
	// TODO - Update Input
}

void Game::OnMouse(int mouseButton, bool down, int xPos, int yPos)
{
	// TODO - Update Input
}