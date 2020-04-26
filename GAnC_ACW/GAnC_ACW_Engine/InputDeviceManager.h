#pragma once
#include "Manager.h"
#include <vector>
#include "BaseMessage.h"
#include "InputProviderType.h"

class BaseInputProvider;

class InputDeviceManager
	: public Manager
{
public:

	enum ButtonInputType
	{
		PRESS,
		RELEASE,
		HOLD,
	};

	InputDeviceManager();
	virtual ~InputDeviceManager();

	BaseInputProvider* GetInputProvider(InputProviderType type);

	bool GetButtonInput(InputProviderType deviceType, int button/*, ButtonInputType inputType*/);
	float GetAxisInput(InputProviderType deviceType, std::string axis);
	// Input Message Handling (routes to correct provider)
	void OnInput(BaseMessage& msg);

	// How do we set the providers?
	void CreateInputProvider(InputProviderType type);

private:

	BaseInputProvider* FindProvider(std::string name);
	BaseInputProvider* FindProvider(InputProviderType type);

	std::vector<BaseInputProvider*> m_inputProviders;
};