#include "Manager.h"

Manager::Manager(const std::string& name)
	: m_name(name)
{
	printf("MANAGER: %s created and initialized.\n", m_name.c_str());
}

Manager::~Manager()
{

}

const std::string& Manager::GetName()
{
	return m_name;
}