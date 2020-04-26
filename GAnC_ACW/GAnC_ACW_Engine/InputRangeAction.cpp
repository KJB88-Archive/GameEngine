#include "InputRangeAction.h"
#include "BaseInputProvider.h"

InputRangeAction::InputRangeAction(std::string name, std::string axisName, BaseInputProvider* inputProvider)
	: BaseInputAction(name, inputProvider, InputActionType::RANGE), m_axisName(axisName)
{

}

InputRangeAction::~InputRangeAction()
{

}

float InputRangeAction::GetActionValue()
{
	return m_inputProvider->GetAxis(m_axisName);
}

std::string InputRangeAction::GetAxisName()
{
	return m_axisName;
}