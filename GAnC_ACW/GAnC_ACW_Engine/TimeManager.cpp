#include "TimeManager.h"

using namespace std::chrono;
#include <ctime>

TimeManager::TimeManager()
	: Manager("Time Manager")
{
	timer = steady_clock();
	m_currentTime = steady_clock::now();
	m_previousTime = steady_clock::now();
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