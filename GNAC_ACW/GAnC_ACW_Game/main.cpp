#include "TestGame.h"

#if DX_BUILD
#include "DXWindow.h"

const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;
const float SCREEN_WIDTH = 800;
const float SCREEN_HEIGHT = 600;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	TestGame game;
	bool result;

	// Move to Logging
	AllocConsole();
	freopen("CONOUT$", "wb", stdout); // Less secure call - use freopen_s in future
	printf("MAIN: Console allocation and initialization complete.\n");

	////GameObject* obj = new GameObject("New Object", "TAG1", Vector3(1.1f, 2.2f, 3.3f));
	//
	////printf("GameObject: %s with tag %s has a position of %f, %f, %f.",
	////	obj->name, obj->tag, obj->transform->position.x, obj->transform->position.y, obj->transform->position.z);

	//printf("GameObject: %s, with Tag: %s, at Position: %f, %f, %f\n", obj->name.c_str(), obj->tag.c_str(), obj->transform->position.x, obj->transform->position.y, obj->transform->position.z);
	////printf("Transform contains a Vector3 of: %f, %f, %f\n", transf->position.x, transf->position.y, transf->position.z);

	DXWindow* window = new DXWindow(&game, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SCREEN_NEAR, hInstance, nShowCmd);

	// Run the game
	game.Run();
}
#endif

#if GL_BUILD
// Do GL stuff
#endif