#pragma once
#include <iostream>
#include <sstream>

namespace RadicalRepresentation
{
	std::string converter(int number, int redix)
	{
		std::string convertedText;

		while (number > 0)
		{
			int val = number%redix;
			number = number / redix;

			// Sending a number as a stream into output string
			std::ostringstream str1;
			str1 << val;
			
			convertedText = str1.str() + convertedText;
		}
		//std::cout << convertedText;

		return convertedText;
	}

	int findBinaryNumber(int number, int pattern)
	{
		int count = 0;
		char pat = pattern + '0';
		std::string binaryString = converter(number, 2);

		for (unsigned int index = 0; index < strlen(binaryString.c_str()); index++)
		{
			//std::cout << binaryString.c_str()[index];

			if (binaryString.c_str()[index] == pat)
			{
				count++;
			}
		}

		return count;
	}

	int findBinaryNumberByBitwise(int number, int pattern)
	{
		int count = 0;

		while (number > 0)
		{
			if ((number & 1) == pattern)
			{
				count++;
			}

			number = number >> 1;
		}

		return count;
	}

	int negativeNumber(int number)
	{
		//return (~number ^ 1 & 1);
		int x = ~number;
		int y = 1;
		// Iterate till there is no carry  
		while (y != 0)
		{
			// carry now contains common 
			//set bits of x and y
			int carry = x & y;

			// Sum of bits of x and y where at 
			//least one of the bits is not set
			x = x ^ y;

			// Carry is shifted by one so that adding
			// it to x gives the required sum
			y = carry << 1;
		}

		return x;
	}
}
