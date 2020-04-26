#pragma once
#include "BaseInputAction.h"

class InputRangeAction
	: public BaseInputAction
{

public:
	InputRangeAction(std::string name, std::string axisName, BaseInputProvider* inputProvider);
	virtual ~InputRangeAction();

	float GetActionValue();
	std::string GetAxisName();

private:

	std::string m_axisName;
};