#pragma once
#include <chrono>
#include "Manager.h"

class TimeManager
	: public Manager
{
public:
	TimeManager();
	~TimeManager();

	void Update();
	void PostUpdate();
	static double GetDeltaTime();

private:

	static double m_deltaTime;

	typedef std::chrono::high_resolution_clock Clock;
	Clock::time_point previousTime;
	Clock::time_point currentTime;

	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;
};