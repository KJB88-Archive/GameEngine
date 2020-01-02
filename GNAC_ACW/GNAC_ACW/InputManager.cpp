#include "InputManager.h"

InputManager::InputManager()
	: Manager("Input Manager")
{
	// Default keys to false
	for (int i = 0; i < 256; ++i)
	{
		m_keys[i] = false;
	}
}

InputManager::~InputManager()
{

}

void InputManager::KeyDown(unsigned int input)
{
	m_keys[input] = true;
}

void InputManager::KeyUp(unsigned int input)
{
	m_keys[input] = false;
}

bool InputManager::IsKeyDown(unsigned int key)
{
	return m_keys[key];
}

void InputManager::MouseDown(unsigned int button, int xPos, int yPos)
{
	m_LMB = true;
}

void InputManager::MouseUp(unsigned int button, int xPos, int yPos)
{
	m_LMB = false;
}

bool InputManager::IsMouseButtonDown(unsigned int button)
{
	return m_LMB;
}