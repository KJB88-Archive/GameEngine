#include "TimeManager.h"

using namespace std::chrono;
#include <ctime>

TimeManager::TimeManager()
	: Manager("Time")
{
	timer = steady_clock();
	m_currentTime = steady_clock::now();
	m_previousTime = steady_clock::now();
	
	m_deltaTime = 0.0f;
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
	m_deltaTime = duration_cast<milliseconds>(m_currentTime - m_previousTime).count();

	m_previousTime = m_currentTime;
}