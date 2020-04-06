#pragma once
#include <string>

class BaseMessage
{
public:
	BaseMessage(std::string type)
		: m_type(type) {};

	virtual ~BaseMessage() {};

	std::string GetType() { return m_type; }

protected:

	std::string m_type;
};