#pragma once
#include "Game.h"

class TestGame
	: public Game
{

public:
	TestGame();
	virtual ~TestGame();

	// Inherited via Game
	virtual void Initialise() override;
	virtual void Reset() override;
	virtual bool Run() override;

private:
};