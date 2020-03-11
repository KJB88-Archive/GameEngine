#include "Game.h"

Game::Game()
	: m_input(nullptr), m_renderer(nullptr), m_time(nullptr), m_sceneManager(nullptr)
{
	// Create Logger Manager
	m_logger = new Logger();
	if (!m_logger)
	{
		Logger::LogToConsole("GAME: Unable to create Logging manager.");
	}

	// Create Time Manager
	m_time = new Time();
	if (!m_time)
	{
		Logger::LogToConsole("GAME: Unable to create TimeManager object.\n");
	}

	// Create Input Manager
	m_input = new Input();
	if (!m_input)
	{
		Logger::LogToConsole("GAME: Unable to create InputManager object.\n");
	}

	// Create Scene Manager
	m_sceneManager = new SceneManager();
	if (!m_sceneManager)
	{
		Logger::LogToConsole("GAME: Unable to create SceneManager object.\n");
	}
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
		m_window = nullptr;
	}
}

void Game::Initialise(Window* window, Renderer* renderer)
{
	m_renderer = renderer;
	m_window = window;
	
	// Create Render System
	m_renderSystem = m_renderer->GetSystem();
	if (!m_renderSystem)
	{
		Logger::LogToConsole("GAME: Unable to get RenderSystem object.\n");
	}

}

bool Game::Run()
{
	// Update managers and systems here
	m_time->Update();

	return m_sceneManager->RunScene(); // Main update call

	// Return false to continue game loop
}

void Game::OnKeyboard(int key, bool down)
{
	m_input->OnKey(key, down);
	m_input->IsKeyDown(key);
}

void Game::OnMouse(int mouseButton, bool down, int xPos, int yPos)
{
	std::string keyStr;
	if (down)
	{
		keyStr = "Mouse down";
	}
	else
	{
		keyStr = "Mouse up";
	}

	Logger::LogToConsole(keyStr);
	// TODO - Update Input
}