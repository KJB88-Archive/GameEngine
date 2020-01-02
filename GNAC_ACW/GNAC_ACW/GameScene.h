#pragma once
#include "Scene.h"
class GameScene
	: public Scene
{

public:

	GameScene();
	virtual ~GameScene();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();

private:
};