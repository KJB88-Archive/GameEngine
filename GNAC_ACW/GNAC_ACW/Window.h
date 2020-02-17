#pragma once
#include "windows.h"
#include "windowsx.h"
#define WIN32_LEAN_AND_MEAN

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static Window* appHandle = 0;

class Window
{
public:

	Window(int& screenWidth, int& screenHeight);
	~Window();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:

	LPCSTR appName;
	HINSTANCE hInstance;
	HWND hWnd;
};

