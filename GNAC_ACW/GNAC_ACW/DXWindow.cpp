#include "DXWindow.h"

DXWindow::DXWindow(int screenWidth, int screenHeight, Input* input)
	: Window(screenWidth, screenHeight, input)
{

}

DXWindow::~DXWindow()
{

}

bool DXWindow::Messaging()
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

LRESULT CALLBACK DXWindow::MessageHandler(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
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