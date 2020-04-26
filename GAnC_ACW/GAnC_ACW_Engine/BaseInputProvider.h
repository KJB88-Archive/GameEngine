#pragma once
#include <string>
#include "InputDeviceManager.h"
#include "Logger.h"

#include "InputProviderType.h"
class BaseInputProvider
{
public:

	BaseInputProvider(std::string name, InputProviderType type)
		: m_name(name), m_providerType(type)
	{
		Logger::LogToConsole("INPUT PROVIDER: Created input provider of type: " + name);
	}
	virtual ~BaseInputProvider() {};

	virtual bool GetButtonDown(unsigned int index)
	{
		Logger::LogToConsole("INPUT PROVIDER: Provider does not implement GetButtonDown: " + m_name);
		return false;
	}

	virtual bool GetButtonUp(unsigned int index)
	{
		Logger::LogToConsole("INPUT PROVIDER: Provider does not implement GetButtonUp: " + m_name);
		return false;
	}

	virtual bool GetButtonHeld(unsigned int index)
	{
		Logger::LogToConsole("INPUT PROVIDER: Provider does not implement GetButtonHeld: " + m_name);
		return false;
	}

	virtual float GetAxis(std::string axis)
	{
		Logger::LogToConsole("INPUT PROVIDER: Provider does not implement GetAxis: " + m_name);
		return 0.0f;
	}

	/// Perform message casting and handling
	virtual void SetInput(BaseMessage& msg) = 0;

	std::string GetName() { return m_name; }
	InputProviderType GetProviderType() { return m_providerType; }

protected:

	std::string m_name;
	InputProviderType m_providerType;
};