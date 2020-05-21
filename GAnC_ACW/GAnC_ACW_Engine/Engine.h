#pragma once
// Core Management
#include "Window.h"
#include "InputDeviceManager.h"
#include "InputManager.h"
#include "Renderer.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "PhysicsManager.h"
#include "CollisionManager.h"

// Static Management
#include "AssetManager.h"
#include "Logger.h"
#include "SystemManager.h"
#include "SubjectManager.h"

/// Engine is the main container for all Engine-based core management
/// A pointer to Engine is held in base class Game and can be used access required resources

class Engine
{
public:

	Engine();
	~Engine();

	// Core Managers
	Window* window() const { return m_window; }
	InputDeviceManager* inputDeviceManager() const { return m_inputDeviceManager; }
	InputManager* inputManager() const { return m_input; }
	Renderer* renderer() const { return m_renderer; }
	TimeManager* timeManager() const { return m_time; }
	SceneManager* sceneManager() const { return m_sceneManager; }
	PhysicsManager* physicsManager() const { return m_physicsManager; }
	CollisionManager* collisionManager() const { return m_collisionManager; }

	// Initialise Engine with window and graphics resources
	void Initialise(Window* window, Renderer* renderer);

	// Update engine resources
	void Update();
	void PostUpdate();

	// Input passthrough
	void OnInput(BaseMessage& msg);

private:

	//// Static Managers
	//AssetManager* assetManager() const { return m_assetManager; }
	//Logger* logger() const { return m_logger; }
	//SystemManager* systemManager() const { return m_systemManager; }
	//SubjectManager* subjectManager() const { return m_subjectManager; }

	// Core Managers
	Window* m_window; // Handles viewport and allows graphics hook
	InputDeviceManager* m_inputDeviceManager; // Handles low-level input from OS/Hardware
	InputManager* m_input; // Handles high-level input for game logic
	Renderer* m_renderer; // Graphics
	TimeManager* m_time; // Handles time related functions (deltaTime, etc)
	SceneManager* m_sceneManager; // Scene manipulation
	PhysicsManager* m_physicsManager; // Physics logic
	CollisionManager* m_collisionManager; // Collision logic

	// Static Managers
	AssetManager* m_assetManager; // Handles creation and loading of assets
	Logger* m_logger; // Logs to console
	SystemManager*  m_systemManager; // Exposes systems to game to allow for scenes to
	SubjectManager* m_subjectManager; // Allows observers to subscribe to specific messages without knowing about subjects

	Engine(const Engine& other) = delete;
	Engine& operator=(const Engine&) = delete;
};