#include "Game.h"
//#include "Transform.h"
//#include "Vector3.h"
//#include "GameObject.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){
	Game* game;
	bool result;

	AllocConsole();
	freopen("CONOUT$", "wb", stdout); // Less secure call - use freopen_s in future
	printf("MAIN: Console allocation and initialization complete.\n");

	////GameObject* obj = new GameObject("New Object", "TAG1", Vector3(1.1f, 2.2f, 3.3f));
	//
	////printf("GameObject: %s with tag %s has a position of %f, %f, %f.",
	////	obj->name, obj->tag, obj->transform->position.x, obj->transform->position.y, obj->transform->position.z);

	//printf("GameObject: %s, with Tag: %s, at Position: %f, %f, %f\n", obj->name.c_str(), obj->tag.c_str(), obj->transform->position.x, obj->transform->position.y, obj->transform->position.z);
	////printf("Transform contains a Vector3 of: %f, %f, %f\n", transf->position.x, transf->position.y, transf->position.z);

	game = new Game();

	if (!game)
	{
		return 0;
	}

	// Run the game
	game->Run();
}