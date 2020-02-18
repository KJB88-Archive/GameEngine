#pragma once
#include "windows.h"
#include "windowsx.h"
#define WIN32_LEAN_AND_MEAN

// Window
#include "Window.h"


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

	//LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:

	bool OnFrame();
	//void InitializeWindows(int&, int&);
	//void ShutdownWindows();

	void CreateCoreManagers(int&, int&);
	void CreateSystems();
	void InitializeWindow(int&, int&);

	//LPCSTR m_applicationName;
	//HINSTANCE m_hInstance;
	//HWND m_hWnd;

	Window* window;

	// Core Managers
	Input* input;
	Graphics* graphics;
	Time* time;
	SceneManager* sceneManager;

	// Systems
	RenderSystem* renderSystem;


	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};
//
//static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//static Game* ApplicationHandle = 0;