#include "InputManager.h"
#include "InputDeviceManager.h"

#include <string>
#include "Logger.h"

// Actions
#include "BaseInputAction.h"
#include "InputStateAction.h"
#include "InputRangeAction.h"

std::map<std::string, BaseInputAction*> InputManager::m_actionMap = std::map<std::string, BaseInputAction*>();

InputManager::InputManager(InputDeviceManager* idm)
	: Manager("Input"), m_inputDeviceManager(idm)
{
	AddBinaryToActionMap("Forward", StateActionType::PRESS, InputProviderType::KEYBOARD, 87);
	AddBinaryToActionMap("Backward", StateActionType::PRESS, InputProviderType::KEYBOARD, 83);
	AddBinaryToActionMap("Left", StateActionType::PRESS, InputProviderType::KEYBOARD, 65);
	AddBinaryToActionMap("Right", StateActionType::PRESS, InputProviderType::KEYBOARD, 68);
	AddBinaryToActionMap("RotateLeft", StateActionType::PRESS, InputProviderType::KEYBOARD, 81);
	AddBinaryToActionMap("RotateRight", StateActionType::PRESS, InputProviderType::KEYBOARD, 69);
}

InputManager::~InputManager()
{
	m_actionMap.clear();
}

bool InputManager::GetButtonDown(std::string action)
{
	// Try to find the action in the map
	ActionMapIterator it = m_actionMap.find(action);

	// If the action exists under the given command
	if (it != m_actionMap.end())
	{
		// Get the type of the action
		InputActionType type = it->second->GetActionType();

		// Check if it's the action we're interested in
		if (type == InputActionType::STATE)
		{
			// Cast the base ptr to the derived ptr
			InputStateAction* stateAction = dynamic_cast<InputStateAction*>(it->second);

			// Check if the cast has worked
			if (stateAction != nullptr)
			{
				// Check if the action is a press
				if (stateAction->GetStateActionType() == StateActionType::PRESS)
				{
					return stateAction->GetActionValue();
				}
			}
		}
	}

	return false;
}

//bool InputManager::GetButtonUp(std::string action)
//{
//	// Try to find the action in the map
//	ActionMapIterator it = m_actionMap.find(action);
//
//	// If the action exists under the given command
//	if (it != m_actionMap.end())
//	{
//		// Get the type of the action
//		InputActionType type = it->second->GetActionType();
//
//		// Check if it's the action we're interested in
//		if (type == InputActionType::STATE)
//		{
//			// Cast the base ptr to the derived ptr
//			InputStateAction* stateAction = dynamic_cast<InputStateAction*>(it->second);
//
//			// Check if the cast has worked
//			if (stateAction != nullptr)
//			{
//				// Check if the action is a press
//				if (stateAction->GetStateActionType() == StateActionType::RELEASE)
//				{
//					return stateAction->GetActionValue();
//				}
//			}
//		}
//	}
//	return false;
//}
//
//bool InputManager::GetButtonHeld(std::string action)
//{
//	// Try to find the action in the map
//	ActionMapIterator it = m_actionMap.find(action);
//
//	// If the action exists under the given command
//	if (it != m_actionMap.end())
//	{
//		// Get the type of the action
//		InputActionType type = it->second->GetActionType();
//
//		// Check if it's the action we're interested in
//		if (type == InputActionType::STATE)
//		{
//			// Cast the base ptr to the derived ptr
//			InputStateAction* stateAction = dynamic_cast<InputStateAction*>(it->second);
//
//			// Check if the cast has worked
//			if (stateAction != nullptr)
//			{
//				// Check if the action is a press
//				if (stateAction->GetStateActionType() == StateActionType::HOLD)
//				{
//					return stateAction->GetActionValue();
//				}
//			}
//		}
//	}
//	return false;
//}
//
//float InputManager::GetAxis(std::string axis)
//{
//	// Try to find the action in the map
//	ActionMapIterator it = m_actionMap.find(axis);
//
//	// If the action exists under the given command
//	if (it != m_actionMap.end())
//	{
//		// Get the type of the action
//		InputActionType type = it->second->GetActionType();
//
//		// Check if it's the action we're interested in
//		if (type == InputActionType::RANGE)
//		{
//			// Cast the base ptr to the derived ptr
//			InputRangeAction* stateAction = dynamic_cast<InputRangeAction*>(it->second);
//
//			// Check if the cast has worked
//			if (stateAction != nullptr)
//			{
//				return stateAction->GetActionValue();
//			}
//		}
//	}
//	return false;
//}

void InputManager::AddBinaryToActionMap(
	std::string actionName, StateActionType binaryType,
	InputProviderType deviceType, int buttonIndex)
{
	// Create action
	InputStateAction* inputAction = new InputStateAction
	(
		actionName,
		binaryType,
		m_inputDeviceManager->GetInputProvider(deviceType),
		buttonIndex
	);

	// Add to map
	m_actionMap.try_emplace(actionName, inputAction);

	// Nullify temporary ptr
	inputAction = nullptr;
}

//
//void InputManager::AddRangeToActionMap(std::string actionName, InputProviderType deviceType)
//{
//	InputRangeAction* inputAction = new InputRangeAction
//	(
//		actionName,
//		actionName,
//		m_inputDeviceManager->GetInputProvider(deviceType)
//	);
//
//	m_actionMap.try_emplace(actionName, inputAction);
//
//	inputAction = nullptr;
//}

BaseInputAction* InputManager::FindAction(std::string action)
{
	ActionMapIterator it = m_actionMap.find(action);

	if (it != m_actionMap.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}