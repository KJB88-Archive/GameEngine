#pragma once
#include "Game.h"


class TestGame
	: public Game
{

public:
	TestGame();
	virtual ~TestGame();


private:

	// Inherited via Game
	virtual void Reset() override;
};