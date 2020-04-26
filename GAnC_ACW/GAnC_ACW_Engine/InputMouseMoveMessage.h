#pragma once
#include "BaseMessage.h"

struct InputMouseMoveMessage
	: public BaseMessage
{
public:
	float m_x;
	float m_y;
};