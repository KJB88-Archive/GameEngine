#include "Game.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	Game* game;
	bool result;

	AllocConsole();
	freopen("CONOUT$", "wb", stdout); // Less secure call - use freopen_s in future
	printf("MAIN: Console allocation and initialization complete.\n");

	game = new Game();

	if (!game)
	{
		return 0;
	}

	// Run the game
	game->Run();
}