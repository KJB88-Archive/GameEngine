#pragma once
#include <chrono>
#include "Manager.h"

class Time
	: public Manager
{
public:
	Time();
	~Time();

	void Update();

	float GetDeltaTime();

private:

	std::chrono::steady_clock timer;

	std::chrono::steady_clock::time_point m_currentTime;
	std::chrono::steady_clock::time_point m_previousTime;
	float m_deltaTime;

	Time(const Time&) = delete;
	Time& operator=(const Time&) = delete;
};