#pragma once
#include <string>

class Component
{

public:

	Component();
	Component(const std::string& inName);
	virtual ~Component();

	const std::string& GetName();
	void ToggleObject();

private:

	std::string name;
	bool isEnabled;

};