#pragma once
// Window
#include "Window.h"

// Management
#include "InputManager.h"
#include "Renderer.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Logger.h"
#include "PhysicsManager.h"
#include "SystemManager.h"

/// Engine is the main container for all Engine-based core management
/// A pointer to Engine is held in base class Game and can be used access required resources

class Engine
{
public:

	Engine();
	~Engine();

	// Core Managers
	Window* window() const { return m_window; }
	InputManager* inputManager() const { return m_input; }
	Renderer* renderer() const { return m_renderer; }
	TimeManager* timeManager() const { return m_time; }
	SceneManager* sceneManager() const { return m_sceneManager; }
	PhysicsManager* physicsManager() const { return m_physicsManager; }

	// Static Managers
	Logger* logger() const { return m_logger; }
	SystemManager* systemManager() const { return m_systemManager; }

	// Initialise Engine with window and graphics resources
	void Initialise(Window* window, Renderer* renderer);

	// Update engine resources
	void Update();

	// Input handling
	void OnKeyboard(int key, bool down);
	void OnMouse(int mouseButton, bool down, int xPos, int yPos);

private:

	// Core Managers
	Window* m_window;
	InputManager* m_input;
	Renderer* m_renderer;
	TimeManager* m_time;
	SceneManager* m_sceneManager;
	PhysicsManager* m_physicsManager;

	// Static Managers
	Logger* m_logger;
	SystemManager*  m_systemManager;

	Engine(const Engine& other) = delete;
	Engine& operator=(const Engine&) = delete;
};