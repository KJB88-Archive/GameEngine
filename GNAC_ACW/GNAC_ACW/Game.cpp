#include "Game.h"

const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

Game::Game()
	: input(nullptr), renderer(nullptr), time(nullptr), sceneManager(nullptr)
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

	if (renderer)
	{
		delete renderer;
		renderer = nullptr;
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
#ifdef DX_BUILD
	renderer = new Renderer(screenWidth, screenHeight, window->GetHWND());
#else
	renderer = new GLRenderer(screenWidth, screenHeight, window->GetHWND())
#endif

	if (!renderer)
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
	renderSystem = new RenderSystem(renderer);
	if (!renderSystem)
	{
		printf("GAME: Unable to create RenderSystem object.\n");
	}
}

void Game::InitializeWindow(int& screenWidth, int& screenHeight)
{
	window = new Window(screenWidth, screenHeight, input);
}

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
	graphics->EndScene();

	return true;
}