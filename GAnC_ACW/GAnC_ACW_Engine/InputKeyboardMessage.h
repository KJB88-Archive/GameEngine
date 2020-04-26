#pragma once
#include "BaseMessage.h"

struct InputKeyboardMessage
	: public BaseMessage
{
public:
	int m_key;
	bool m_down;
};