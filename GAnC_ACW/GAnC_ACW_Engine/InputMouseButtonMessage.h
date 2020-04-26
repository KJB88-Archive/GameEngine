#pragma once
#include "BaseMessage.h"

struct InputMouseButtonMessage
	: public BaseMessage
{
public:
	int m_button;
	bool m_down;
};