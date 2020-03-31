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
	m_time = new TimeManager();
	if (!m_time)
	{
		Logger::LogToConsole("GAME: Unable to create TimeManager object.");
	}

	// Create Input Manager
	m_input = new InputManager();
	if (!m_input)
	{
		Logger::LogToConsole("GAME: Unable to create InputManager object.");
	}

	// Create Scene Manager
	m_sceneManager = new SceneManager();
	if (!m_sceneManager)
	{
		Logger::LogToConsole("GAME: Unable to create SceneManager object.");
	}

	m_physicsManager = new PhysicsManager();
	if (!m_physicsManager)
	{
		Logger::LogToConsole("GAME: Unable to create PhysicsManager object.");
	}
	m_systemManager = new SystemManager();
	if (!m_systemManager)
	{
		Logger::LogToConsole("GAME: Unable to create SystemManager object.");
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

	SystemManager::AddSystem(m_renderer->GetSystem());
	SystemManager::AddSystem(m_physics->GetSystem());
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
}

void Game::OnMouse(int mouseButton, bool down, int xPos, int yPos)
{
	m_input->OnMouse(mouseButton, down, xPos, yPos);
}