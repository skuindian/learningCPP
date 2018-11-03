#pragma once

#include <iostream>
#include <map>

namespace NVariousAlgoImplementation
{
	/*
	* Problem - 01
	*
	* Problem Statement:
	*
	* There is 3 department in the office
	* 1 - Fire, 2 - Polish, 3- Sanity
	* We need to assign unique number to each department
	* Number should be in range of 1 to 7
	* Police department can not take the odd number
	* Count of all number should be equal to 12
	* 
	* Input:
	* lowerRangeNum = 1, higherRangeNum = 7, totalCount = 12
	*
	* Output:
	* fireNumber, polishNumber, sanityNumber:3,2,7
	* fireNumber, polishNumber, sanityNumber:4,2,6
	* fireNumber, polishNumber, sanityNumber:6,2,4
	* fireNumber, polishNumber, sanityNumber:7,2,3
	* fireNumber, polishNumber, sanityNumber:1,4,7
	* fireNumber, polishNumber, sanityNumber:2,4,6
	* fireNumber, polishNumber, sanityNumber:3,4,5
	* fireNumber, polishNumber, sanityNumber:5,4,3
	* fireNumber, polishNumber, sanityNumber:6,4,2
	* fireNumber, polishNumber, sanityNumber:7,4,1
	* fireNumber, polishNumber, sanityNumber:1,6,5
	* fireNumber, polishNumber, sanityNumber:2,6,4
	* fireNumber, polishNumber, sanityNumber:4,6,2
	* fireNumber, polishNumber, sanityNumber:5,6,1
	*/

	void solveProblem01(int lowerRangeNum, int higherRangeNum, int totalCount)
	{
		for (int iIndex = lowerRangeNum; iIndex <= higherRangeNum; iIndex++)
		{
			int fireNumber = 0;
			int polishNumber = 0;
			int sanityNumber = 0;

			if (iIndex % 2 == 0)
			{
				polishNumber = iIndex;
				int countToConsider = totalCount - polishNumber;

				for (int jIndex = lowerRangeNum; jIndex <= higherRangeNum; jIndex++)
				{
					if (jIndex != polishNumber)
					{
						fireNumber = jIndex;
						sanityNumber = countToConsider - fireNumber;

						if ((fireNumber != sanityNumber) && 
							(polishNumber + fireNumber + sanityNumber == totalCount) 	&& 
							(polishNumber <= higherRangeNum && polishNumber >= lowerRangeNum) &&
							(fireNumber <= higherRangeNum && fireNumber >= lowerRangeNum) &&
							(sanityNumber <= higherRangeNum && sanityNumber >= lowerRangeNum))
						{
							std::cout << "fireNumber, polishNumber, sanityNumber:" << fireNumber << "," << polishNumber << "," << sanityNumber << "\n";
						}
					}
				}
			}
		}
	} //End of problem 01

	/*
	* Problem - 02
	*
	* Problem Statement:
	*
	* Have a sequence of array (ex 20) or list which has repetive number between 0-9
	* Find count of repetive number
	* Find unique number
	*
	* Input:
	* 1, 3, 5, 4, 1, 4, 5, 6, 1, 2, 4, 7, 9, 2, 1, 2, 5, 6, 9, 8
	*
	* Output:
	* Element 1 Count = 4
	* Element 2 Count = 3
	* Element 3 Count = 2
	* Element 4 Count = 3
	* Element 5 Count = 2
	* Element 6 Count = 2
	* Element 7 Count = 1
	* Element 8 Count = 1
	* Element 9 Count = 2
	*/
	void solveProblem02_01(int inputArr[], int size)
	{
		std::sort(inputArr, inputArr+size);

		int count = 1;
		for (int index = 0; index < size - 1; index++)
		{
			if (inputArr[index] == inputArr[index + 1])
			{
				count++;
			}
			else
			{
				std::cout << "Element " << inputArr[index] << " Count = " << count << std::endl;
				count = 1;
			}

			//Finally print the last number
			if (index == (size - 2))
			{
				std::cout << "Element " << inputArr[index] << " Count = " << count << std::endl;
			}
		}
	}

	void solveProblem02_02(int inputArr[], int size)
	{
		std::map<int, int> arrMap;

		for (int index = 0; index < size; index++)
		{
			int count = 0;
			arrMap[inputArr[index]] = arrMap[inputArr[index]] + (++count);
		}

		//Display elements of map
		std::map<int, int> ::iterator itr;

		for (itr = arrMap.begin(); itr != arrMap.end(); itr++)
		{
			std::cout << "Number:" << itr->first <<  ", Count:" << itr->second << std::endl;

		}
	}
}