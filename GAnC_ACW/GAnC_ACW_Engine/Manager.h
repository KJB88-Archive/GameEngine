#pragma once
#include <string>

class Manager
{
public:

	Manager(const std::string& name);
	virtual ~Manager();

	const std::string& GetName();

private:
	const std::string& m_name;

};