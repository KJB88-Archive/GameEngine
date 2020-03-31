#pragma once
#include "Scene.h"
#include "RenderSystem.h"

class GameScene
	: public Scene
{

public:

	GameScene(int id, SceneManager* sm);
	virtual ~GameScene();

	virtual bool RunScene() override;

private:

};