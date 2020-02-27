#pragma once
#include "Input.h"

class Window
{
public:

	Window(int screenWidth, int screenHeight, Input* input);
	~Window();

private:

	int screenWidth;
	int screenHeight;

	Input* input;

};

