#pragma once
#include "Manager.h"
#include <map>

// Type Enums
#include "InputProviderType.h"
#include "StateActionType.h"

class BaseInputAction;
class InputDeviceManager;

class InputManager
	: public Manager
{
public:

	InputManager(InputDeviceManager* idm);
	virtual ~InputManager();

	/// Game-logic input
	static bool GetButtonDown(std::string action); // Was this action pressed this frame?
	//static bool GetButtonUp(std::string action); // Was this action released this frame?
	//static bool GetButtonHeld(std::string action); // Is this action held down?
	//static float GetAxis(std::string axis); // Return the value of the given axis

	// External access to mapping for other classes (Maybe don't need this?)
	//void AddActionToMap(std::string name, InputDeviceType type, int buttonIndex);

private:

	/// Action Map Manipulation
	void AddBinaryToActionMap(std::string actionName, StateActionType binaryType, InputProviderType deviceType, int buttonIndex);
	//void AddRangeToActionMap(std::string actionName, InputProviderType deviceType);
	BaseInputAction* FindAction(std::string action);

	/// Used to get required input data from hardware
	InputDeviceManager* m_inputDeviceManager;

	typedef std::map<std::string, BaseInputAction*> ActionMap;
	typedef std::map<std::string, BaseInputAction*>::iterator ActionMapIterator;
	static ActionMap m_actionMap;

	InputManager(const InputManager&) = delete;
	InputManager* operator=(const InputManager&) = delete;
};