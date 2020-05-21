#include "TimeManager.h"

using namespace std::chrono;
#include <ctime>
// TODO - Make this manager handle spawning new Time objects for Thread timing

double TimeManager::m_deltaTime = 0;

TimeManager::TimeManager()
	: Manager("Time")
{
	//timer = high_resolution_clock();
	//m_currentTime = high_resolution_clock::now();
	//m_previousTime = high_resolution_clock::now();
	//
	//m_deltaTime = 0.0f;

	previousTime = Clock::now();
}

TimeManager::~TimeManager()
{

}

double TimeManager::GetDeltaTime()
{
	return m_deltaTime;
}

//m_currentTime = timer.now();
//m_deltaTime = duration_cast<milliseconds>(m_currentTime - m_previousTime).count();

void TimeManager::Update()
{
	currentTime = Clock::now();
	using ms = duration<double, std::milli>;
	double elapsed = duration_cast<ms>((currentTime - previousTime) / 1000.0f).count();

	m_deltaTime = elapsed;
}

void TimeManager::PostUpdate()
{
	previousTime = currentTime;
}

//	auto currentTime = std::chrono::high_resolution_clock::now();
//	auto elapsed = m_previousTime - currentTime;
//
//	m_deltaTime = elapsed.count();
//
//	m_previousTime = currentTime;
//}