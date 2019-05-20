#pragma once
#include "Manager.h"
class InputManager
	: public Manager
{
public:
	InputManager();
	virtual ~InputManager();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	bool IsKeyDown(unsigned int);

	void MouseDown(unsigned int, int, int);
	void MouseUp(unsigned int, int, int);
	bool IsMouseButtonDown(unsigned int);

private:

	bool m_keys[256];
	bool m_LMB;

	InputManager(const InputManager&) = delete;
	InputManager* operator=(const InputManager&) = delete;
};