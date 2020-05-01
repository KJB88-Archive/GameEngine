#include "MouseInputProvider.h""

#include "InputMouseButtonMessage.h"
#include "InputMouseMoveMessage.h"

MouseInputProvider::MouseInputProvider()
	: BaseInputProvider("Mouse", InputProviderType::MOUSE)
{
	for (int i = 0; i < 3; ++i)
	{
		m_buttons[i] = false;
		m_lastButtons[i] = false;
	}
}

MouseInputProvider::~MouseInputProvider()
{

}

void MouseInputProvider::Update()
{
	for (int i = 0; i < 3; ++i)
	{
		m_lastButtons[i] = m_buttons[i];
		m_buttons[i] = false;
	}
}

float MouseInputProvider::GetAxis(std::string axis)
{
	if (axis == "MouseX")
	{
		return m_x;
	}
	else if (axis == "MouseY")
	{
		return  m_y;
	}
}

bool MouseInputProvider::GetButtonDown(unsigned int button)
{
	if (button >= 3)
	{
		return false;
	}

	if (m_buttons[button] && !m_lastButtons[button])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MouseInputProvider::GetButtonUp(unsigned int button)
{
	if (button >= 3)
	{
		return false;
	}

	if (!m_buttons[button] && m_lastButtons[button])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MouseInputProvider::GetButtonHeld(unsigned int button)
{
	if (button >= 3)
	{
		return false;
	}

	if (m_buttons[button] && m_lastButtons[button])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MouseInputProvider::SetInput(BaseMessage& msg)
{
	if (msg.m_type == "InputMouseMove")
	{
		InputMouseMoveMessage input = (InputMouseMoveMessage&)msg;

		m_x = input.m_x;
		m_y = input.m_y;

		//Logger::LogToConsole("MOUSE PROVIDER: Movement detected.");
	}
	else if (msg.m_type == "InputMouseButton")
	{
		InputMouseButtonMessage input = (InputMouseButtonMessage&)msg;

		m_lastButtons[input.m_button] = m_buttons[input.m_button];
		m_buttons[input.m_button] = input.m_down;

		//if (input.m_down)
		//{
		//	Logger::LogToConsole("MOUSE PROVIDER: Button pressed.");
		//}
		//else
		//{
		//	Logger::LogToConsole("MOUSE PROVIDER: Button released.");
		//}
	}
}

void MouseInputProvider::OnMouseMove(float x, float y)
{
	m_x = x;
	m_y = y;
}

void MouseInputProvider::OnMouseClick(int button, bool down)
{
	m_lastButtons[button] = m_buttons[button];
	m_buttons[button] = down;
}