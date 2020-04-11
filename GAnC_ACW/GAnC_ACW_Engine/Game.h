#pragma once
#include "Engine.h"

class Game
{
public:
	Game() : m_engine(new Engine()) {};
	~Game() { delete m_engine; m_engine = nullptr; };

	// Get pointer to Engine
	Engine* engine() const { return m_engine; }

	// Setup resources before run
	virtual void Initialise() = 0;

	// Main game loop
	virtual bool Run() = 0;

protected:

	// Reset game
	virtual void Reset() = 0;

private:

	Engine* m_engine;

	Game(const Game&) = delete;
	Game* operator=(const Game&) = delete;
};