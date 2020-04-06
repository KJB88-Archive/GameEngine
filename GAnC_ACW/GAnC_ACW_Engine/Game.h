#pragma once
// Window
#include "Window.h"

// Management
#include "InputManager.h"
#include "Renderer.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Logger.h"
#include "SystemManager.h"
#include "PhysicsManager.h"

class Game
{
public:
	Game();
	~Game();

	// TODO - Abstract this class and enforce any children to implement ALL functionality

	// Setup external resources
	virtual void Initialise(Window* wnd, Renderer* window);

	// Main game loop
	virtual bool Run();

	// Input
	virtual void OnKeyboard(int key, bool down);
	virtual void OnMouse(int mouseButton, bool down, int xPos, int yPos);

protected:

	// Reset game
	virtual void Reset() = 0;

	// Core Managers
	Window* m_window;
	InputManager* m_input;
	Renderer* m_renderer;
	TimeManager* m_time;
	SceneManager* m_sceneManager;
	PhysicsManager* m_physicsManager;
	Logger* m_logger;
	SystemManager*  m_systemManager;

private:

	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};