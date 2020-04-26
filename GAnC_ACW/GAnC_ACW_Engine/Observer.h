#pragma once
#include "BaseMessage.h"

class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}

	virtual void OnNotify(BaseMessage* msg) = 0;
};
