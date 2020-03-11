#include "Manager.h"
#include "Logger.h"

Manager::Manager(const std::string& name)
	: m_name(name)
{
	if (name != "Logger")
	{
		Logger::LogToConsole("MANAGER: " + m_name + " created and initialized.");
	}
}

Manager::~Manager()
{

}

const std::string& Manager::GetName()
{
	return m_name;
}