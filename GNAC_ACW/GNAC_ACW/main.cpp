#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR pScmdline, int CmdShow)
{
	Game* game;
	bool result;

	game = new Game();

	if (!game)
	{
		return 0;
	}

	// Run the game
	game->Run();
}