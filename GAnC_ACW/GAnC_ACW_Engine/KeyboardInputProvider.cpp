#include "KeyboardInputProvider.h"
#include "InputKeyboardMessage.h"

KeyboardInputProvider::KeyboardInputProvider()
	: BaseInputProvider("Keyboard", InputProviderType::KEYBOARD)
{
	for (int i = 0; i < 256; ++i)
	{
		m_keys[i] = false;
		m_lastKeys[i] = false;
	}
}

KeyboardInputProvider::~KeyboardInputProvider()
{

}

void KeyboardInputProvider::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		m_lastKeys[i] = m_keys[i];
		m_keys[i] = false;
	}
}

bool KeyboardInputProvider::GetButtonDown(unsigned int i)
{
	if (i >= 256)
	{
		return false;
	}

	if (m_keys[i] && !m_lastKeys[i])
	{
		m_keys[i] = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool KeyboardInputProvider::GetButtonUp(unsigned int i)
{
	if (i >= 256)
	{
		return false;
	}

	if (!m_keys[i] && m_lastKeys[i])
	{
		m_lastKeys[i] = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool KeyboardInputProvider::GetButtonHeld(unsigned int i)
{
	if (i >= 256)
	{
		return false;
	}

	if (m_keys[i] && m_lastKeys[i])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void KeyboardInputProvider::SetInput(BaseMessage& msg)
{
	if (msg.m_type == "InputKeyboard")
	{
		InputKeyboardMessage input = (InputKeyboardMessage&)msg;

		m_lastKeys[input.m_key] = m_keys[input.m_key];
		m_keys[input.m_key] = input.m_down;

		//if (input.m_down)
		//{
		//	Logger::LogToConsole("KEYBOARD PROVIDER: Key was pressed.");
		//}
		//else
		//{
		//	Logger::LogToConsole("KEYBOARD PROVIDER: Key was released.");
		//}
	}
}