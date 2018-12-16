#pragma once
#include <iostream>
#include <string>

namespace QuickTest
{
	class QuickTest
	{
	public:
		//Reference:
		//https://www.toptal.com/c-plus-plus/interview-questions
		//https://en.cppreference.com/w/Main_Page
		//

		/*
		 * The answer is not -25. Rather, the answer (which will surprise many) is 
		 * 4294967271, assuming 32 bit integers. Why?
		 *
		 * In C++, if the types of two operands differ from one another, then the 
		 * operand with the “lower type” will be promoted to the type of the 
		 * “higher type” operand, using the following type hierarchy (listed here 
		 * from highest type to lowest type): long double, double, float, unsigned 
		 * long int, long int, unsigned int, int (lowest).
		 *
		 * So when the two operands are, as in our example, 25u (unsigned int) and 
		 * 50 (int), the 50 is promoted to also being an unsigned integer 
		 * (i.e., 50u).
		 *
		 * Moreover, the result of the operation will be of the type of the operands. 
		 * Therefore, the result of 25u - 50u will itself be an unsigned integer 
		 * as well. So the result of -25 converts to 4294967271 when promoted to being 
		 * an unsigned integer.
		*/
		static void concept01()
		{
			std::cout << 25u - 50;
			std::cout << std::endl;
			std::cout << 25.4 - 10;
		}
	};
}