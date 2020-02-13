#include "Game.h"

Game::Game()
	: m_input(nullptr), m_graphics(nullptr), m_time(nullptr), m_scene(nullptr)
{
	int screenWidth = 0, screenHeight = 0;
	bool result;

	// Initialize the Window
	InitializeWindows(screenWidth, screenHeight);

	// MANAGERS
	// Create Time Manager
	m_time = new TimeManager();
	if (!m_time)
	{
		printf("GAME: Unable to create TimeManager object.\n");
	}

	// Create Input Manager
	m_input = new InputManager();
	if (!m_input)
	{
		printf("GAME: Unable to create InputManager object.\n");
	}

	// Create Graphics Manager
	m_graphics = new GraphicsManager(screenWidth, screenHeight, m_hWnd);
	if (!m_graphics)
	{
		printf("GAME: Unable to create GraphicsManager object.\n");
	}

	// Create Scene Manager
	m_scene = new SceneManager();
	if (!m_scene)
	{
		printf("GAME: Unable to create SceneManager object.\n");
	}

	// SYSTEMS
	// Create Render System
	m_renderSystem = new RenderSystem(m_graphics);
	if (!m_renderSystem)
	{
		printf("GAME: Unable to create RenderSystem object.\n");
	}
}

Game::~Game()
{
	if (m_time)
	{
		delete m_time;
		m_time = nullptr;
	}

	if (m_graphics)
	{
		delete m_graphics;
		m_graphics = nullptr;
	}

	if (m_input)
	{
		delete m_input;
		m_input = nullptr;
	}

	if (m_scene)
	{
		delete m_scene;
		m_scene = nullptr;
	}

	ShutdownWindows();
}

void Game::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;

	// Implement windows application data
	ApplicationHandle = this;
	m_hInstance = GetModuleHandle(NULL);
	m_applicationName = "Engine";

	// Setup Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register window class
	RegisterClassEx(&wc);

	screenWidth = 800;
	screenHeight = 600;
	posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
	posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;

	// Create window and get handle
	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_OVERLAPPEDWINDOW, posX, posY, screenWidth, screenHeight, NULL, NULL, m_hInstance, NULL);

	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);
}

void Game::ShutdownWindows()
{
	DestroyWindow(m_hWnd);
	m_hWnd = nullptr;

	UnregisterClass(m_applicationName, m_hInstance);
	m_hInstance = nullptr;

	ApplicationHandle = nullptr;
}

void Game::Run()
{
	MSG msg;
	bool done, result;

	// Init. MSG
	ZeroMemory(&msg, sizeof(MSG));

	// Loop until quit
	done = false;
	while (!done)
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
			done = true;
		}
		else
		{
			// Loop game logic
			result = OnFrame();
			if (!result)
			{
				done = true;
			}
		}
	}

	return;
}

bool Game::OnFrame()
{
	bool result;

	// Check if we want to close the application
	// TODO - Replace with main menu??
	if (m_input->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	// Update
	m_scene->UpdateScene(m_time->GetDeltaTime()); // Main update call

	// Render
	m_graphics->BeginScene();
	m_scene->RenderScene(m_renderSystem); // Main render call
	//m_graphics->Draw();
	m_graphics->EndScene();

	return true;
}

LRESULT CALLBACK Game::MessageHandler(HWND hWnd, UINT umsg, WPARAM wParam, LPARAM lParam)
{
	switch (umsg)
	{
		// Keyboard checks
	case WM_KEYDOWN:
		m_input->KeyDown((unsigned int)wParam);
		break;

	case WM_KEYUP:
		m_input->KeyUp((unsigned int)wParam);
		break;

	case WM_LBUTTONDOWN:
		m_input->MouseDown((unsigned int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;

	case WM_LBUTTONUP:
		m_input->MouseUp((unsigned int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;

	default:
		return DefWindowProc(hWnd, umsg, wParam, lParam);
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
		return ApplicationHandle->MessageHandler(hWnd, uMessage, wParam, lParam);
	}
}