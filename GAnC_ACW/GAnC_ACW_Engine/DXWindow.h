#pragma once
#include "windows.h"
#include "windowsx.h"
#define WIN32_LEAN_AND_MEAN

#include "Input.h"
#include "Window.h"

class DXWindow
	: public Window
{
public:

	DXWindow(Game* game, int screenWidth, int screenHeight, float screenDepth, float screenNear, HINSTANCE hInstance, int nCmdShow);
	~DXWindow();

	//bool Messaging();
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

	virtual void Run() override;

private:

	bool Messaging();

	HWND m_hWnd;
	LPCSTR m_appName;
	HINSTANCE m_hInstance;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static DXWindow* APPHANDLE = 0;

