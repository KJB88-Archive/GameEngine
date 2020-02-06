#pragma once

class ISystem
{
public:

	enum SystemType
	{
		SYSTEM_TRANSFORM,
		SYSTEM_RENDER,
	};

	ISystem(SystemType type)
	{
		systemType = type;
	}

	virtual SystemType SystemType() = 0;
private:

	SystemType systemType;
};