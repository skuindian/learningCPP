#pragma once

#include <iostream>

namespace FriendFunction
{
	class DerivedClass;
	class BaseClass
	{
		int val;
	public:
		BaseClass(int pVal)
		{
			val = pVal;
		}

		friend void compute(BaseClass bClass, DerivedClass dClass);
	};

	class DerivedClass
	{
		int val;
	public:
		DerivedClass(int pVal)
		{
			val = pVal;
		}
		friend void compute(BaseClass bClass, DerivedClass dClass);
	};

	void compute(BaseClass bClass, DerivedClass dClass)
	{
		std::cout << bClass.val + dClass.val << std::endl;
	}
}