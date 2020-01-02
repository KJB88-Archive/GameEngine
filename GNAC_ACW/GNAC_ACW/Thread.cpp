//#include "Thread.h"
//
//unsigned __stdcall Thread::ThreadFunction(void* param)
//{
//	if (param)
//	{
//		return ((Thread*)param)->ThreadMain();
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//Thread::Thread()
//	: abort(false)
//{
//}
//
//Thread::~Thread()
//{
//
//}
//
////std::thread Thread::Start()
////{
////	worker = std::thread(ThreadFunction);
////
////	return worker;
////}
//
//void Thread::Abort()
//{
//	abort = true;
//}
//
//bool Thread::IsAborted()
//{
//	return abort;
//}
//
//void Thread::WaitForAbort()
//{
//
//}
//
