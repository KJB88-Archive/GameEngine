#include "Engine.h"

Engine::Engine()
	: m_logger(nullptr), m_time(nullptr), m_input(nullptr), m_sceneManager(nullptr),
	m_physicsManager(nullptr), m_systemManager(nullptr)
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

	// Create Physics Manager
	m_physicsManager = new PhysicsManager();
	if (!m_physicsManager)
	{
		Logger::LogToConsole("GAME: Unable to create PhysicsManager object.");
	}

	// Create System Manager
	m_systemManager = new SystemManager();
	if (!m_systemManager)
	{
		Logger::LogToConsole("GAME: Unable to create SystemManager object.");
	}
}

Engine::~Engine()
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

	if (m_physicsManager)
	{
		delete m_physicsManager;
		m_physicsManager = nullptr;
	}

	if (m_sceneManager)
	{
		delete m_sceneManager;
		m_sceneManager = nullptr;
	}

	if (m_systemManager)
	{
		delete m_systemManager;
		m_systemManager = nullptr;
	}

	if (m_window)
	{
		// Window is deleted by application, not Engine or Game
		m_window = nullptr;
	}

	if (m_logger)
	{
		delete m_logger;
		m_logger = nullptr;
	}
}

void Engine::Initialise(Window* window, Renderer* renderer)
{
	m_window = window;
	m_renderer = renderer;
}

void Engine::Update()
{
	m_time->Update();
}

void Engine::OnKeyboard(int key, bool down)
{
	m_input->OnKey(key, down);
}

void Engine::OnMouse(int mouseButton, bool down, int xPos, int yPos)
{
	m_input->OnMouse(mouseButton, down, xPos, yPos);
}