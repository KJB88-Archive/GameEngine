#pragma once
// Window
#include "Window.h"

// Management
#include "Input.h"
#include "Renderer.h"
#include "Time.h"
#include "SceneManager.h"
#include "Logger.h"

// Systems
#include "RenderSystem.h"

class Game
{
public:
	Game();
	~Game();

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
	Input* m_input;
	Renderer* m_renderer;
	Time* m_time;
	SceneManager* m_sceneManager;
	Logger* m_logger;

	// Systems
	RenderSystem* m_renderSystem;

private:

	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};