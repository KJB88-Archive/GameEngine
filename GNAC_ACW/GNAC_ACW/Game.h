#pragma once
#include "windows.h"
#include "windowsx.h"
#define WIN32_LEAN_AND_MEAN

// Window
#include "Window.h"

// Management
#include "Input.h"
#include "Renderer.h"
#include "Time.h"
#include "SceneManager.h"

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
	virtual void Run();

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

	// Systems
	RenderSystem* m_renderSystem;

private:

	void CreateSystems();

	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};