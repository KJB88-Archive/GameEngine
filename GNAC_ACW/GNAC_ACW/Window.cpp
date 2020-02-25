#include "Window.h"

Window::Window(int& screenWidth, int& screenHeight, Input* input)
	:input(input), appName(NULL), hInstance(NULL), hWnd(NULL),
	screenWidth(screenWidth), screenHeight(screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;

	// Implement windows application data
	appHandle = this;
	hInstance = GetModuleHandle(NULL);
	appName = "Engine";

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
	wc.lpszClassName = appName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register window class
	RegisterClassEx(&wc);

	screenWidth = 800;
	screenHeight = 600;
	posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
	posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;

	// Create window and get handle
	hWnd = CreateWindowEx(WS_EX_APPWINDOW, appName, appName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_OVERLAPPEDWINDOW, posX, posY, screenWidth, screenHeight, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);
	SetForegroundWindow(hWnd);
	SetFocus(hWnd);

	// Set up messaging
	ZeroMemory(&msg, sizeof(MSG));

	printf("WINDOW: Created and initialized.\n");
}

Window::~Window()
{
	DestroyWindow(hWnd);
	hWnd = nullptr;

	UnregisterClass(appName, hInstance);
	hInstance = nullptr;

	appHandle = nullptr;
}

HWND Window::GetWindowHandle()
{
	return hWnd;
}

LPCSTR Window::GetAppName()
{
	return appName;
}

HINSTANCE Window::GetHINSTANCE()
{
	return hInstance;
}

bool Window::Messaging()
{
	// Handle Windows Messaging
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// If exit signal
	if (msg.message == WM_QUIT)
	{
		return true;
	}

	return false;
}

LRESULT CALLBACK Window::MessageHandler(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
		// Keyboard checks
	case WM_KEYDOWN:
		input->KeyDown((unsigned int)wParam);
		break;

	case WM_KEYUP:
		input->KeyUp((unsigned int)wParam);
		break;

	case WM_LBUTTONDOWN:
		input->MouseDown((unsigned int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;

	case WM_LBUTTONUP:
		input->MouseUp((unsigned int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
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
		return appHandle->MessageHandler(hWnd, uMessage, wParam, lParam);
	}
}