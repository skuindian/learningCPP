#pragma once
#include <iostream>
#include <string>

namespace QuickTest
{
	class QuickTest
	{
	public:
		int var;

		static void testFunction()
		{
			std::cout << "Inside Static Function" << std::endl;
		}
	};
}