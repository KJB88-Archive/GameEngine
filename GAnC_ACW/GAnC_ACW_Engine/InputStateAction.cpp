#include "InputStateAction.h"

#include "BaseInputProvider.h"

InputStateAction::InputStateAction(std::string name, StateActionType stateType, BaseInputProvider* inputProvider, int buttonIndex)
	: BaseInputAction(name, inputProvider, InputActionType::STATE),
	m_stateType(stateType), m_actionIndex(buttonIndex)
{

}

InputStateAction::~InputStateAction()
{

}

StateActionType InputStateAction::GetStateActionType()
{
	return m_stateType;
}

bool InputStateAction::GetActionValue()
{
	switch (m_stateType)
	{
	case StateActionType::PRESS:
		return m_inputProvider->GetButtonDown(m_actionIndex);
	case StateActionType::HOLD:
		return m_inputProvider->GetButtonHeld(m_actionIndex);
	case StateActionType::RELEASE:
		return m_inputProvider->GetButtonUp(m_actionIndex);
	}

	return false;
}