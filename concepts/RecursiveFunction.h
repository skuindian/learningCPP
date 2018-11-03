#pragma once

#include <iostream>
#include <cmath>

namespace NRecursiveFunction
{

	int getAbs(int sensorA[], int sensorB[], int size)
	{
		size--;
		int result = std::abs(sensorA[size] - sensorB[size]);

		if (size == 0)
		{
			return result;
		}
		result += getAbs(sensorA, sensorB, size);
	}
}