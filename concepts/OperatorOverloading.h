#pragma once

#include <iostream>

namespace OperatorOverloading
{
	class BaseClass
	{
		int val;

	public:
		BaseClass()
		{

		}

		BaseClass(int pVal)
		{
			val = pVal;
		}

		BaseClass operator / (BaseClass bClass)
		{
			BaseClass tBClass;
			if (bClass.val == 0)
			{
				tBClass.val = 0;
			}
			else
			{
				tBClass = this->val / bClass.val;
			}
			return tBClass;
		}

		int getVal()
		{
			return val;
		}
	};
}