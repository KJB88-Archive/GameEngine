#pragma once
#include "Manager.h"
#include "BaseSystem.h"
#include <vector>

class SystemManager
	: public Manager
{
public:

	SystemManager();
	virtual ~SystemManager();

	static BaseSystem* GetSystem(std::string systemName);
	static BaseSystem* GetSystem(BaseSystem::SystemType systemType);

	static void AddSystem(BaseSystem* system);

private:

	static std::vector<BaseSystem*> systems;
};