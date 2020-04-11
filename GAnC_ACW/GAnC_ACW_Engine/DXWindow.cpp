#include "DXWindow.h"
#include "DXRenderer.h"
#include "Game.h"
#include "Logger.h"

DXWindow::DXWindow(Game* game, int screenWidth, int screenHeight, float screenDepth, float screenNear, HINSTANCE hInstance, int nCmdShow)
	: Window(screenWidth, screenHeight, game, screenDepth, screenNear)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;

	// Implement windows application data
	APPHANDLE = this;
	m_hInstance = hInstance;
	m_appName = "GAnC ACW";

	// Setup Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_appName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register window class
	RegisterClassEx(&wc);

	posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
	posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;

	// Create window and get handle
	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, m_appName, m_appName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_OVERLAPPEDWINDOW, posX, posY, screenWidth, screenHeight, NULL, NULL, m_hInstance, NULL);

	ShowWindow(m_hWnd, nCmdShow);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);

	Logger::LogToConsole("WINDOW: Created and initialized.");

	// Initialise Game & Renderer
	m_game->engine()->Initialise(this, new DXRenderer(m_screenWidth, m_screenHeight, m_hWnd, m_screenDepth, m_screenNear));
	m_game->Initialise();

}

DXWindow::~DXWindow()
{
	DestroyWindow(m_hWnd);
	m_hWnd = nullptr;

	UnregisterClass(m_appName, m_hInstance);
	m_hInstance = nullptr;

	APPHANDLE = nullptr;
}

void DXWindow::Run()
{
	bool done = false;

	// Loop until quit
	while (!done) // TODO - This loop is causing hard lock?
	{
		// Window messaging
		if (Messaging())
		{
			done = true;
		}

		done = m_game->Run();
	}
	return;
}

bool DXWindow::Messaging()
{
	MSG msg;

	// Set up messaging
	ZeroMemory(&msg, sizeof(MSG));

	// Handle Windows Messaging
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		// If exit signal
		if (msg.message == WM_QUIT)
		{
			return true;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return false;
}

LRESULT CALLBACK DXWindow::MessageHandler(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_KEYDOWN:
		// Exit application
		if (wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
		}
		m_game->engine()->OnKeyboard((unsigned int)wParam, true);
		break;

	case WM_KEYUP:
		m_game->engine()->OnKeyboard((unsigned int)wParam, false);
		break;

	case WM_LBUTTONDOWN:
		m_game->engine()->OnMouse((unsigned int)wParam, true, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;

	case WM_LBUTTONUP:
		m_game->engine()->OnMouse((unsigned int)wParam, false, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;

	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;

	default:
		return APPHANDLE->MessageHandler(hWnd, uMessage, wParam, lParam);
	}
}