#pragma once
#include "Game.h"
#include "ObserverSubject.h"
#include "Observer.h"

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

	virtual void NotifyAll(BaseMessage* msg) override;
	virtual void OnNotify(BaseMessage* msg) override;
private:

};