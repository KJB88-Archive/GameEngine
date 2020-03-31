#include "SystemManager.h"

// Static vector of systems
std::vector<BaseSystem*> SystemManager::systems;

SystemManager::SystemManager()
	: Manager("System")
{

}

SystemManager::~SystemManager()
{

}

BaseSystem* SystemManager::GetSystem(std::string systemName)
{
	for (int i = 0; i < systems.size(); ++i)
	{
		if (systems[i]->GetName() == systemName)
		{
			return systems[i];
		}
	}
}

BaseSystem* SystemManager::GetSystem(BaseSystem::SystemType systemType)
{
	for (int i = 0; i < systems.size(); ++i)
	{
		if (systems[i]->GetType() == systemType)
		{
			return systems[i];
		}
	}
}

void SystemManager::AddSystem(BaseSystem* system)
{
	systems.emplace_back(system);
}