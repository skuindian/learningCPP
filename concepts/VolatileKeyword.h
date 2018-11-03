#pragma once
#include <Windows.h>
#include <iostream>

namespace VolatileKeyword
{
	volatile int runTest = 100;

	void testFunction()
	{
		while (runTest == 100)
		{
			std::cout << "Inside testFunction()" << std::endl;
			Sleep(1000);
		}
	}
}