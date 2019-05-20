#pragma once
#include <string>

class Manager
{
public:

	Manager(std::string name)
		: m_name(name) {};
	virtual ~Manager() {};

	std::string GetName() { return m_name; }

private:
	std::string m_name;
};