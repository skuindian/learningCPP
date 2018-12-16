#pragma once

#include <iostream>
#include <map>

/*
 * The STL map and multimap Containers. The map and the multimap are both containers that 
 * manage key/value pairs as single components. 
 
 * The essential difference between the two is that in a map the keys must be unique, 
 * while a multimap permits duplicate keys.
 */
namespace NDSmapVSmultimap
{
	class BaseClass
	{
		std::map<int, std::string> mVowelsID;

	public:
		BaseClass()
		{
			mVowelsID[1] = "A";
			mVowelsID[2] = "E";
			mVowelsID[3] = "I";
			mVowelsID[4] = "O";
			mVowelsID[5] = "U";
			//mVowelsID[5] = "S"; //Will override the map index
		}

		void getVowel(int index)
		{
			if (index < 1 || index > mVowelsID.size())
			{
				std::cout << "Invalid Index" << std::endl;
				return;
			}
			std::cout << mVowelsID[index] << std::endl;
		}

		void getCompleteVowelList()
		{
			for (std::map<int, std::string> ::iterator itr = mVowelsID.begin(); itr != mVowelsID.end(); itr++)
			{
				std::cout << itr->first << "," << itr->second << std::endl;
			}
		}
	};
}