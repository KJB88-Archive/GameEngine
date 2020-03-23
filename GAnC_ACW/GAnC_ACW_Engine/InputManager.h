#pragma once
#include "Manager.h"

class InputManager
	: public Manager
{
public:
	InputManager();
	virtual ~InputManager();

	void OnKey(unsigned int key, bool downState);
	bool IsKeyDown(unsigned int);

	void OnMouse(unsigned int key, bool downState, int xPos , int yPos);
	bool IsMouseButtonDown(unsigned int);

private:

	bool m_keys[256];
	bool m_LMB;

	InputManager(const InputManager&) = delete;
	InputManager* operator=(const InputManager&) = delete;
};