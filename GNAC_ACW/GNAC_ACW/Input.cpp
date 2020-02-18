#include "Input.h"
#include <string>

Input::Input()
	: Manager("Input")
{
	// Default keys to false
	for (int i = 0; i < 256; ++i)
	{
		m_keys[i] = false;
	}

}

Input::~Input()
{

}

void Input::KeyDown(unsigned int input)
{
	if (m_keys)
	{
		m_keys[input] = true;
	}
	else
	{
		printf("...");
	}
}

void Input::KeyUp(unsigned int input)
{
	m_keys[input] = false;
}

bool Input::IsKeyDown(unsigned int key)
{
	return m_keys[key];
}

void Input::MouseDown(unsigned int button, int xPos, int yPos)
{
	m_LMB = true;
}

void Input::MouseUp(unsigned int button, int xPos, int yPos)
{
	m_LMB = false;
}

bool Input::IsMouseButtonDown(unsigned int button)
{
	return m_LMB;
}