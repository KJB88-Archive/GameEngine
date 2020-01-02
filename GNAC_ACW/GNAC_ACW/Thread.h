//#pragma once
//#include <Windows.h>
//#include <thread>
//
//class Thread
//{
//public:
//	Thread();
//	virtual ~Thread();
//
//	void Abort();
//	bool IsAborted();
//	std::thread Start();
//	void WaitForAbort();
//	virtual int ThreadMain() = 0;
//
//private:
//
//	static unsigned __stdcall ThreadFunction(void *param);
//	std::thread worker;
//	bool abort;
//};