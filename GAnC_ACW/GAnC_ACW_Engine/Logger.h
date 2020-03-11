#pragma once
#include <string>
#include "Manager.h"

// IF WINDOWS
#include <Windows.h>
//ELSE other OS

class Logger
	: public Manager
{
public:

	Logger();
	virtual ~Logger();

	static void LogToConsole(std::string error);
	static void LogToConsole(HRESULT result, std::string error);
	static void LogToConsole(const char* error);
	//static void LogToConsole(std::wstring error);

private:
};