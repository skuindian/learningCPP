#pragma once

namespace NLambdaFunctionPtr
{
	//Concepts:
	//Pointer arithmetic on void* is not allowed by the standard.
	/*
	void trackCounter(int counter)
	{
		std::cout << "Counter Val:" << counter << std::endl;
	}*/
	
	class GenricTimer
	{
		bool mTimer;
	public:
		GenricTimer()
		{
			mTimer = false;
		}

		bool startTimer(unsigned int sec, void (*pFun)(int))
		{
			mTimer = true;

			//Wait for timer then call function


			if (mTimer)
			{
				//Call function
				pFun(10);
			}

			return true;
		}

		bool stopTimer()
		{
			mTimer = false;
			return true;
		}
	};

	void simpleFunction(int val)
	{
		std::cout << "I am inside simple function:" << val << std::endl;
		GenricTimer gTimer;

		//Define a void function pointer
		//int *p = &t;
		//void (*pFun)(int) = &trackCounter;
		//void(*pFun)(int) = [](int counter) {std::cout << "Lambda Counter Val:" << counter << std::endl;};

		auto lambdaFun = [](int counter) {std::cout << "Lambda Counter Val:" << counter << std::endl; };
		void(*pFun)(int) = lambdaFun;

		gTimer.startTimer(1000, pFun);
	}

}