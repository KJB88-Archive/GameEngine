#pragma once
#include "Scene.h"
#include "RenderSystem.h"

class GameScene
	: public Scene
{

public:

	GameScene();
	virtual ~GameScene();

	virtual bool RunScene() override;

private:

};