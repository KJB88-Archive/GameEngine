#include "Component.h"

Component::Component()
	: name("NO NAME"), isEnabled(true)
{

}

Component::Component(const std::string& inName)
	: name(inName), isEnabled(true)
{

}

Component::~Component()
{

}

const std::string& Component::GetName()
{
	return name;
}

void Component::ToggleObject()
{
	isEnabled = !isEnabled;
}