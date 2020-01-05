#include "Component.h"

Component::Component()
	: name("NO NAME"), isEnabled(true)
{
	printf("COMPONENT: %s created.\n", name.c_str());
}

Component::Component(const std::string& inName)
	: name(inName), isEnabled(true)
{
	printf("COMPONENT: %s created.\n", name.c_str());
}

Component::Component(const Component& other)
	: name("NO NAME"), isEnabled(true)
{
	name = other.name;
	isEnabled = other.isEnabled;

	printf("COMPONENT: %s created via copy.\n", name.c_str());
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