#include "Game.h"

Game::Game()
	: input(nullptr), graphics(nullptr), time(nullptr), sceneManager(nullptr)
{
	int screenWidth = 0, screenHeight = 0;
	bool result;

	// Initialize the Window
	//InitializeWindows(screenWidth, screenHeight);

	InitializeWindow(screenWidth, screenHeight);
	CreateCoreManagers(screenWidth, screenHeight);
	CreateSystems();

}

Game::~Game()
{
	if (time)
	{
		delete time;
		time = nullptr;
	}

	if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}

	if (input)
	{
		delete input;
		input = nullptr;
	}

	if (sceneManager)
	{
		delete sceneManager;
		sceneManager = nullptr;
	}

	//ShutdownWindows();
}

void Game::CreateCoreManagers(int& screenWidth, int& screenHeight)
{
	// Create Time Manager
	time = new Time();
	if (!time)
	{
		printf("GAME: Unable to create TimeManager object.\n");
	}

	// Create Input Manager
	input = new Input();
	if (!input)
	{
		printf("GAME: Unable to create InputManager object.\n");
	}

	// Create Graphics Manager
	graphics = new Graphics(screenWidth, screenHeight, window->GetHWND());
	if (!graphics)
	{
		printf("GAME: Unable to create GraphicsManager object.\n");
	}

	// Create Scene Manager
	sceneManager = new SceneManager();
	if (!sceneManager)
	{
		printf("GAME: Unable to create SceneManager object.\n");
	}
}

void Game::CreateSystems()
{
// Create Render System
	renderSystem = new RenderSystem(graphics);
	if (!renderSystem)
	{
		printf("GAME: Unable to create RenderSystem object.\n");
	}
}

void Game::InitializeWindow(int& screenWidth, int& screenHeight)
{
	window = new Window(screenWidth, screenHeight, input);
}

//void Game::InitializeWindows(int& screenWidth, int& screenHeight)
//{
//	WNDCLASSEX wc;
//	DEVMODE dmScreenSettings;
//	int posX, posY;
//
//	// Implement windows application data
//	ApplicationHandle = this;
//	m_hInstance = GetModuleHandle(NULL);
//	m_applicationName = "Engine";
//
//	// Setup Window
//	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = m_hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
//	wc.hIconSm = wc.hIcon;
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = m_applicationName;
//	wc.cbSize = sizeof(WNDCLASSEX);
//
//	// Register window class
//	RegisterClassEx(&wc);
//
//	screenWidth = 800;
//	screenHeight = 600;
//	posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
//	posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
//
//	// Create window and get handle
//	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName,
//		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_OVERLAPPEDWINDOW, posX, posY, screenWidth, screenHeight, NULL, NULL, m_hInstance, NULL);
//
//	ShowWindow(m_hWnd, SW_SHOW);
//	SetForegroundWindow(m_hWnd);
//	SetFocus(m_hWnd);
//}

//void Game::ShutdownWindows()
//{
//	DestroyWindow(m_hWnd);
//	m_hWnd = nullptr;
//
//	UnregisterClass(m_applicationName, m_hInstance);
//	m_hInstance = nullptr;
//
//	ApplicationHandle = nullptr;
//}

void Game::Run()
{
	MSG msg;
	bool done, result;
	// Loop until quit
	done = false;
	while (!done)
	{
		// Window messaging
		if (window->Messaging())
		{
			done = true;
		}
		else
		{
			// Loop game logic
			result = OnFrame();

			// Game is over, exit 
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

	// If Escape is pressed, close the application
	if (input->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	// Update
	sceneManager->UpdateScene(time->GetDeltaTime()); // Main update call

	// Render
	graphics->BeginScene();
	sceneManager->RenderScene(renderSystem); // Main render call
	//m_graphics->Draw();
	graphics->EndScene();

	return true;
}

//LRESULT CALLBACK Game::MessageHandler(HWND hWnd, UINT umsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (umsg)
//	{
//		// Keyboard checks
//	case WM_KEYDOWN:
//		m_input->KeyDown((unsigned int)wParam);
//		break;
//
//	case WM_KEYUP:
//		m_input->KeyUp((unsigned int)wParam);
//		break;
//
//	case WM_LBUTTONDOWN:
//		m_input->MouseDown((unsigned int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
//		break;
//
//	case WM_LBUTTONUP:
//		m_input->MouseUp((unsigned int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
//		break;
//
//	default:
//		return DefWindowProc(hWnd, umsg, wParam, lParam);
//	}
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMessage)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//
//	case WM_CLOSE:
//		PostQuitMessage(0);
//		return 0;
//
//	default:
//		return ApplicationHandle->MessageHandler(hWnd, uMessage, wParam, lParam);
//	}
//}