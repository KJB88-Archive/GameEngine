#pragma once
#include "Manager.h"
class Input
	: public Manager
{
public:
	Input();
	virtual ~Input();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	bool IsKeyDown(unsigned int);

	void MouseDown(unsigned int, int, int);
	void MouseUp(unsigned int, int, int);
	bool IsMouseButtonDown(unsigned int);

private:

	bool m_keys[256];
	bool m_LMB;

	Input(const Input&) = delete;
	Input* operator=(const Input&) = delete;
};