#pragma once
#include "windows.h"
#include "windowsx.h"
#define WIN32_LEAN_AND_MEAN

#include "InputManager.h"
#include "GraphicsManager.h"

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

	LPCWSTR m_applicationName;
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	InputManager* m_input;
	GraphicsManager* m_graphics;

	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static Game* ApplicationHandle = 0;