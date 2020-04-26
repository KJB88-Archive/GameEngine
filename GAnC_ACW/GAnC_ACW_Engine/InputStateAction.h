#pragma once
#include "BaseInputAction.h"
#include "StateActionType.h"

class InputStateAction
	: public BaseInputAction
{
public:

	InputStateAction(std::string name, StateActionType binaryType, BaseInputProvider* inputProvider, int buttonIndex);
	virtual ~InputStateAction();

	StateActionType GetStateActionType();
	bool GetActionValue();

private:

	StateActionType m_stateType;
	int m_actionIndex;
};