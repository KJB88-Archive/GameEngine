#pragma once
#include "BaseInputProvider.h"

class MouseInputProvider
	: public BaseInputProvider
{
public:

	MouseInputProvider();
	virtual ~MouseInputProvider();

	virtual bool GetButtonDown(unsigned int index) override;
	virtual bool GetButtonUp(unsigned int index) override;
	virtual bool GetButtonHeld(unsigned int index) override;
	virtual float GetAxis(std::string axis) override;

	virtual void Update() override;
	virtual void SetInput(BaseMessage& msg) override;

private:

	void OnMouseMove(float x, float y);
	void OnMouseClick(int button, bool down);

	bool m_buttons[3];
	bool m_lastButtons[3];

	float m_x;
	float m_y;
};