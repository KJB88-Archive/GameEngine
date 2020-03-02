#include "Time.h"

using namespace std::chrono;
#include <ctime>

Time::Time()
	: Manager("Time")
{
	timer = steady_clock();
	m_currentTime = steady_clock::now();
	m_previousTime = steady_clock::now();
}

Time::~Time()
{

}

float Time::GetDeltaTime()
{
	return m_deltaTime;
}

void Time::Update()
{
	m_currentTime = timer.now();
	m_deltaTime = duration_cast<milliseconds>(m_previousTime - m_currentTime).count();

	m_previousTime = m_currentTime;
}