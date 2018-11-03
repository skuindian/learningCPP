#pragma once
namespace NPalindrome
{
	bool checkNumberPalindrome(unsigned int number)
	{
		auto oldNumber = number;
		auto modNumber = 0;

		while (number)
		{
			auto offsetNumber = number % 10;
			number = number / 10;
			modNumber = 10 * modNumber + offsetNumber;
		}

		if (modNumber == oldNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool checkStringPalindrome(char *str)
	{
		char ch;

		char *orgStr = str;
		int sizeOfStr = strlen(str);
		//int sizeStr = sizeof(str); //Will not work
		char *newStr = new char[sizeOfStr + 1];
		newStr[sizeOfStr] = '\0';

		while (*str)
		{
			ch = *str;
			str++;

			std::cout << "ch:" << ch << std::endl;
			newStr[--sizeOfStr] = ch;
		}

		std::cout << "Reverse of the string is:" << newStr;
		
		if (strcmp(orgStr, newStr) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool checkStringPalindromeWithoutRev(char *str)
	{
		int size = strlen(str) - 1;
		for (int index = 0; index <= strlen(str); index++)
		{
			if (str[index] != str[size--])
			{
				return false;
			}

			if (index > size)
			{
				break;
			}
		}

		return true;
	}
}