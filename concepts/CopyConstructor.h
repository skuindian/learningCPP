#pragma once

#include <iostream>

//The problem with default copy constructor(and assignment operator) is – When 
//we have members which dynamically gets initialized at run time, default copy 
//constructor copies this members with address of dynamically allocated memory 
//and not real copy of this memory.Now both the objects points to the same 
//memory and changes in one reflects in another object, Further the main 
//disastrous effect is, when we delete one of this object other object still 
//points to same memory, which will be dangling pointer, and memory leak is 
//also possible problem with this approach.
//
//Hense, in such cases, we should always write our own copy constructor
//(and assignment operator).

namespace CopyConstructor
{
	typedef struct
	{
		int *tokenData;
		std::string tokenName;
	}MessageToken;

	class BaseClass
	{
		int val;
		MessageToken mMessageToken;
	public:

		//Once you explicitly declare absolutely any constructor for a class, 
		//the compiler stops providing the implicit default constructor.If you 
		//still need the default constructor, you have to explicitly declare 
		//and define it yourself.
		
		BaseClass()
		{
			std::cout << "Inside BaseClass" << std::endl;
		}
		/*
		BaseClass(const BaseClass &bClass)
		{
			std::cout << "Inside BaseClass Copy Constructor" << std::endl;
			val = bClass.val;

			mMessageToken.tokenData = new int[10];
			for (int index = 0; index < 10; index++)
			{
				mMessageToken.tokenData[index] = (index + 1) * -1;
			}

			mMessageToken.tokenName = "Default";
		}*/

		void setVal(int pVal)
		{
			val = pVal;
		}

		void initializeMessageToken()
		{
			mMessageToken.tokenData = new int[10];
			for (int index = 0; index < 10; index++)
			{
				mMessageToken.tokenData[index] = index + 1;
			}

			mMessageToken.tokenName = "Default";
		}

		void updateMessageToken()
		{
			for (int index = 0; index < 10; index++)
			{
				mMessageToken.tokenData[index] = index + 2;
			}

			mMessageToken.tokenName = "Updated";
		}

		void cleanMessageToken()
		{
			delete[]mMessageToken.tokenData;
			mMessageToken.tokenName = "";
		}

		void getMessageToken()
		{
			std::cout << "\nToken values are:";
			for (int index = 0; index < 10; index++)
			{
				if (index == 9)
				{
					std::cout << mMessageToken.tokenData[index] << "[" << &mMessageToken.tokenData[index]  << "]";
				}
				else
				{
					std::cout << mMessageToken.tokenData[index] << "[" << &mMessageToken.tokenData[index] << "]" << ",";
				}
			}

			std::cout << "\nToken name is:";

			std::cout << mMessageToken.tokenName;
		}

		int getVal()
		{
			return val;
		}
	};
}