#include "BaseInputAction.h"
#include "BaseInputProvider.h"

BaseInputAction::BaseInputAction(std::string name, BaseInputProvider* inputProvider, InputActionType type)
	: m_name(name), m_inputProvider(inputProvider), m_type(type)
{

}

BaseInputAction::~BaseInputAction()
{
	m_inputProvider = nullptr;
}

std::string BaseInputAction::GetActionName()
{
	return m_name;
}

InputActionType BaseInputAction::GetActionType()
{
	return m_type;
}

void BaseInputAction::SetProvider(BaseInputProvider* provider)
{
	m_inputProvider = provider;
}

