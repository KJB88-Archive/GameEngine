#include "TimeManager.h"

using namespace std::chrono;
#include <ctime>

TimeManager::TimeManager()
	: Manager("Time")
{
	timer = steady_clock();
	m_currentTime = steady_clock::now();
	m_previousTime = steady_clock::now();

	printf("TIME: TimeManager created and initialized.\n");
}

TimeManager::~TimeManager()
{

}

float TimeManager::GetDeltaTime()
{
	return m_deltaTime;
}

void TimeManager::Update()
{
	m_currentTime = timer.now();
	m_deltaTime = duration_cast<milliseconds>(m_previousTime - m_currentTime).count();

	m_previousTime = m_currentTime;
}