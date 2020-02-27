#pragma once
#include "Scene.h"
#include "RenderSystem.h"

class GameScene
	: public Scene
{

public:

	GameScene();
	virtual ~GameScene();

	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(RenderSystem* renderer);

private:

	RenderSystem* renderSystem;
};