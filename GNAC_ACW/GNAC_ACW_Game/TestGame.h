#pragma once
#include "Game.h"


class TestGame
	: public Game
{

public:
	TestGame();
	virtual ~TestGame();

	// Inherited via Game
	virtual void Initialise(Window* wnd, Renderer* renderer);
	virtual void Reset() override;
	virtual bool Run() override;

private:

};