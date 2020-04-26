#pragma once
#include <string>

#include "InputActionType.h"
#include "InputProviderType.h"

class BaseInputProvider;

class BaseInputAction
{
public:

	BaseInputAction(std::string name, BaseInputProvider* inputProvider, InputActionType type);
	virtual ~BaseInputAction();

	void SetProvider(BaseInputProvider* provider);

	std::string GetActionName();
	InputActionType GetActionType();

protected:

	BaseInputProvider* m_inputProvider;

private:

	std::string m_name;
	InputActionType m_type;
};
