#include "Input.h"
#include <string>
#include "Logger.h"

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

void Input::OnKey(unsigned int key, bool down)
{
	m_keys[key] = down;

}

//void Input::KeyDown(unsigned int input)
//{
//	if (m_keys)
//	{
//		m_keys[input] = true;
//	}
//	else
//	{
//		printf("...");
//	}
//}
//
//void Input::KeyUp(unsigned int input)
//{
//	m_keys[input] = false;
//}

bool Input::IsKeyDown(unsigned int key)
{
	if (m_keys[key])
	{
		Logger::LogToConsole("KEY: State is true.");
	}
	else
	{
		Logger::LogToConsole("KEY: State is false.");
	}

	return m_keys[key];
}

void Input::OnMouse(unsigned int button, bool down, int xPos, int yPos)
{
	m_LMB = down;
}

bool Input::IsMouseButtonDown(unsigned int button)
{
	return m_LMB;
}