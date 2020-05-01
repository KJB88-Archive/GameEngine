#include "InputDeviceManager.h"
#include "Logger.h"

// Providers
#include "KeyboardInputProvider.h"
#include "MouseInputProvider.h"

// Messaging
#include "InputKeyboardMessage.h"
#include "InputMouseButtonMessage.h"
#include "InputMouseMoveMessage.h"

InputDeviceManager::InputDeviceManager()
	: Manager("Input Device")
{
	// Create required providers
	CreateInputProvider(InputProviderType::KEYBOARD);
	CreateInputProvider(InputProviderType::MOUSE);
}

InputDeviceManager::~InputDeviceManager()
{
	m_inputProviders.clear();
}

void InputDeviceManager::PostUpdate()
{
	for (int i = 0; i < m_inputProviders.size(); ++i)
	{
		m_inputProviders[i]->Update();
	}
}

BaseInputProvider* InputDeviceManager::GetInputProvider(InputProviderType type)
{
	BaseInputProvider* provider = FindProvider(type);

	return provider;

}

float InputDeviceManager::GetAxisInput(InputProviderType deviceType, std::string axis)
{
	return 0.0f;
}

void InputDeviceManager::CreateInputProvider(InputProviderType type)
{
	switch (type)
	{
	case KEYBOARD:
		m_inputProviders.emplace_back(new KeyboardInputProvider());
		m_inputProviders[m_inputProviders.size() - 1];
		break;

	case MOUSE:
		m_inputProviders.emplace_back(new MouseInputProvider());
		m_inputProviders[m_inputProviders.size() - 1];
		break;

		//case GAMEPAD:
		//	break;

	default:
		Logger::LogToConsole("INPUT DEVICE MANAGER: Requested Input Provider does not exist. Ignoring request.");
		break;
	}
}

void InputDeviceManager::OnInput(BaseMessage& msg)
{
	for (int i = 0; i < m_inputProviders.size(); ++i)
	{
		m_inputProviders[i]->SetInput(msg);
	}
}

BaseInputProvider* InputDeviceManager::FindProvider(std::string name)
{
	for (int i = 0; i < m_inputProviders.size(); ++i)
	{
		if (m_inputProviders[i]->GetName() == name)
		{
			return m_inputProviders[i];
		}
	}
}

BaseInputProvider* InputDeviceManager::FindProvider(InputProviderType type)
{
	for (int i = 0; i < m_inputProviders.size(); ++i)
	{
		if (m_inputProviders[i]->GetProviderType() == type)
		{
			return m_inputProviders[i];
		}
	}
}