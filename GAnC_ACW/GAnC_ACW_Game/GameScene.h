#pragma once
#include "Scene.h"
#include "RenderSystem.h"

class GameScene
	: public Scene
{

public:

	GameScene(int id, Camera* mainCam, SceneManager* sm);
	virtual ~GameScene();

	virtual bool RunScene() override;

private:
};