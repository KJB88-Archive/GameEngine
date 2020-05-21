#include "Engine.h"

Engine::Engine()
	: m_logger(nullptr), m_time(nullptr), m_input(nullptr), m_inputDeviceManager(nullptr), m_sceneManager(nullptr),
	m_physicsManager(nullptr), m_systemManager(nullptr), m_assetManager(nullptr), m_subjectManager(nullptr)
{
	// Create Logger Manager
	m_logger = new Logger();
	if (!m_logger)
	{
		Logger::LogToConsole("ENGINE: Unable to create Logging manager.");
	}

	// Create Time Manager
	m_time = new TimeManager();
	if (!m_time)
	{
		Logger::LogToConsole("ENGINE: Unable to create TimeManager object.");
	}

	// Create Input Device Manager
	m_inputDeviceManager = new InputDeviceManager();
	if (!m_inputDeviceManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create InputDeviceManager object.");
	}

	// Create Input Manager
	m_input = new InputManager(m_inputDeviceManager);
	if (!m_input)
	{
		Logger::LogToConsole("ENGINE: Unable to create InputManager object.");
	}

	// Create Scene Manager
	m_sceneManager = new SceneManager();
	if (!m_sceneManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create SceneManager object.");
	}

	// Create Physics Manager
	m_physicsManager = new PhysicsManager();
	if (!m_physicsManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create PhysicsManager object.");
	}

	m_collisionManager = new CollisionManager();
	if (!m_collisionManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create CollisionManager object.");
	}

	// Create System Manager
	m_systemManager = new SystemManager();
	if (!m_systemManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create SystemManager object.");
	}

	// Create Asset Manager
	m_assetManager = new AssetManager();
	if (!m_assetManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create AssetManager object.");
	}

	// Create Subject Manager
	m_subjectManager = new SubjectManager();
	if (!m_subjectManager)
	{
		Logger::LogToConsole("ENGINE: Unable to create SubjectManager object.");
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

	if (m_inputDeviceManager)
	{
		delete m_inputDeviceManager;
		m_inputDeviceManager = nullptr;
	}

	if (m_physicsManager)
	{
		delete m_physicsManager;
		m_physicsManager = nullptr;
	}

	if (m_collisionManager)
	{
		delete m_collisionManager;
		m_collisionManager = nullptr;
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

	if (m_assetManager)
	{
		delete m_assetManager;
		m_assetManager = nullptr;
	}

	if (m_subjectManager)
	{
		delete m_subjectManager;
		m_subjectManager = nullptr;
	}

	if (m_window)
	{
		// Window is deleted by application, not Engine or Game
		m_window = nullptr;
	}

	// Delete logger last as errors may occur due destruction of other objects
	if (m_logger)
	{
		delete m_logger;
		m_logger = nullptr;
	}
}

/// Initialize and hook into low-level structures
void Engine::Initialise(Window* window, Renderer* renderer)
{
	m_window = window;
	m_renderer = renderer;
}
/// Update  engine resources
void Engine::Update()
{
	// Keep timing updated
	m_time->Update();

}

/// Update engine resources before next frame
void Engine::PostUpdate()
{
	m_time->PostUpdate();
	m_inputDeviceManager->PostUpdate();
}

/// Pass input through to input device manager
void Engine::OnInput(BaseMessage& msg)
{
	if (m_inputDeviceManager)
	{
		m_inputDeviceManager->OnInput(msg);
	}
}