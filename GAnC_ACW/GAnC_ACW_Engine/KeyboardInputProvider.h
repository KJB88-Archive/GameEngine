#pragma once
#include "BaseInputProvider.h"

class KeyboardInputProvider
	: public BaseInputProvider
{
public:

	KeyboardInputProvider();
	virtual ~KeyboardInputProvider();

	virtual bool GetButtonDown(unsigned int index) override;
	virtual bool GetButtonUp(unsigned int index) override;
	virtual bool GetButtonHeld(unsigned int index) override;

	virtual void Update() override;
	virtual void SetInput(BaseMessage& msg) override;

private:

	bool m_keys[256];
	bool m_lastKeys[256];
};