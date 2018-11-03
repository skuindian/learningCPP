#pragma once

#include <iostream>

namespace CallbackFunction
{	
	class MyTimerClass
	{
		static bool timerStopped;

	public:
		//Note: put this call inside thread
		static void startTimer(int(*pFun)(), int timeout)
		{
			timerStopped = false;

			//Add wait code here
			Sleep(timeout);

			if (!timerStopped)
			{
				std::cout << "Time out..." << (*pFun)() << std::endl;
			}
			else
			{
				std::cout << "Timer is already stoped..." << std::endl;
			}
		}

		static void stopTimer()
		{
			timerStopped = true;
		}
	};


	bool MyTimerClass::timerStopped = false;

		
	class MyClass
	{
	public:
		static int handleTimeout();
	};

	int MyClass::handleTimeout()
	{
		std::cout << "Timeout, show error message" << std::endl;
		return -1;
	}
}