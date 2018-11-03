#pragma once

#include <iostream>

namespace CopyConstructor
{
	class BaseClass
	{
		int val;
	public:

		//Once you explicitly declare absolutely any constructor for a class, 
		//the compiler stops providing the implicit default constructor.If you 
		//still need the default constructor, you have to explicitly declare 
		//and define it yourself.
		
		BaseClass()
		{
			std::cout << "Inside BaseClass" << std::endl;
		}

		BaseClass(const BaseClass &bClass)
		{
			std::cout << "Inside BaseClass Copy Constructor" << std::endl;
			val = bClass.val;
		}

		void setVal(int pVal)
		{
			val = pVal;
		}

		int getVal()
		{
			return val;
		}
	};
}