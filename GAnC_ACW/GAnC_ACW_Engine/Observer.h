#pragma once
#include "BaseMessage.h"

class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}

protected:

	virtual void OnNotify(BaseMessage* msg) = 0;
};
