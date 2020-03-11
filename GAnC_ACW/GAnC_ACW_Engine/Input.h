#pragma once
#include "Manager.h"
class Input
	: public Manager
{
public:
	Input();
	virtual ~Input();

	void OnKey(unsigned int key, bool downState);
	bool IsKeyDown(unsigned int);

	void OnMouse(unsigned int key, bool downState, int xPos , int yPos);
	bool IsMouseButtonDown(unsigned int);

private:

	bool m_keys[256];
	bool m_LMB;

	Input(const Input&) = delete;
	Input* operator=(const Input&) = delete;
};