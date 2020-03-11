#include "Logger.h"
#include <iostream>

using namespace std;

Logger::Logger()
	: Manager("Logger")
{
	// Move to Logging
	AllocConsole();
	freopen("CONOUT$", "wb", stdout); // Less secure call - use freopen_s in future
	Logger::LogToConsole("MANAGER: Logger created and initialized.");
}

Logger::~Logger()
{

}

void Logger::LogToConsole(string error)
{
	cout << error << endl;
}

void Logger::LogToConsole(HRESULT result, string error)
{
	cout << error << result << endl;
}

void Logger::LogToConsole(const char* error)
{
	cout << error << endl;
}