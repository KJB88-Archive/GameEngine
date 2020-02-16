#pragma once
#include "windows.h"
#include "windowsx.h"
#define WIN32_LEAN_AND_MEAN

// Management
#include "Input.h"
#include "Graphics.h"
#include "Time.h"
#include "SceneManager.h"

// Systems
#include "RenderSystem.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:

	bool OnFrame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

	LPCSTR m_applicationName;
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	// Core Managers
	Input* m_input;
	Graphics* m_graphics;
	Time* m_time;
	SceneManager* m_scene;

	// Systems
	RenderSystem* m_renderSystem;


	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static Game* ApplicationHandle = 0;