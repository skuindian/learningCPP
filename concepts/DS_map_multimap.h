#pragma once

#include <iostream>
#include <map>

/*
 The STL map and multimap Containers. The map and the multimap are both 
 containers that manage key/value pairs as single components. 
 
 Maps are associative containers that store elements formed by a combination 
 of a key value and a mapped value, following a specific order.
 
 Multimaps are associative containers that store elements formed by a 
 combination of a key value and a mapped value, following a specific order, 
 and where multiple elements can have equivalent keys.
 
 The essential difference between the two is that in a map the keys must be 
 unique, while a multimap permits duplicate keys.
 
 */
namespace NDSmapVSmultimap
{
	class BaseClass
	{
		std::map<int, std::string> mVowelsID;
		std::multimap<int, std::string> mMultiAlphabetID;
		std::multimap<std::string, std::string> mColorItems;

	public:
		BaseClass()
		{
			//Initialize map
			mVowelsID[1] = "A";
			mVowelsID[2] = "E";
			mVowelsID[3] = "I";
			mVowelsID[4] = "O";
			mVowelsID[5] = "U";
			//mVowelsID[5] = "S"; //Will override the map index

			//Initialize multimap
			mMultiAlphabetID.insert(std::pair<int, std::string>(1, "A"));
			mMultiAlphabetID.insert(std::pair<int, std::string>(2, "E"));
			mMultiAlphabetID.insert(std::pair<int, std::string>(3, "I"));
			mMultiAlphabetID.insert(std::pair<int, std::string>(4, "O"));
			mMultiAlphabetID.insert(std::pair<int, std::string>(5, "U"));
			mMultiAlphabetID.insert(std::pair<int, std::string>(5, "S"));

			//Initialize multimap
			mColorItems.insert(std::pair<std::string, std::string>("red", "Tomato Ketchup"));
			mColorItems.insert(std::pair<std::string, std::string>("green", "Fresh Grash"));
			mColorItems.insert(std::pair<std::string, std::string>("yellow", "Mango"));
			mColorItems.insert(std::pair<std::string, std::string>("blue", "Water"));
			mColorItems.insert(std::pair<std::string, std::string>("green", "Fresh Vegetables"));
			mColorItems.insert(std::pair<std::string, std::string>("blue", "Sky"));
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

		void getAlphabet(int index)
		{
			if (index < 1 || index > mMultiAlphabetID.size())
			{
				std::cout << "Invalid Index" << std::endl;
				return;
			}
			//std::cout << mMultiAlphabetID.find(index) << std::endl;
			std::multimap<int, std::string> ::iterator itr = mMultiAlphabetID.find(index);

			while (itr != mMultiAlphabetID.end())
			{
				if (itr->first != index)
				{
					break;
				}
				std::cout << itr->first << "," << itr->second << std::endl;
				itr++;
			}
		}

		void getCompleteVowelList()
		{
			for (std::map<int, std::string> ::iterator itr = mVowelsID.begin(); itr != mVowelsID.end(); itr++)
			{
				std::cout << itr->first << "," << itr->second << std::endl;
			}
		}

		void getCompleteAlphabetList()
		{
			for(std::multimap<int, std::string> ::iterator itr = mMultiAlphabetID.begin(); itr != mMultiAlphabetID.end(); itr++)
			{
				std::cout << itr->first << "," << itr->second << std::endl;
			}
		}

		void getColorItems(std::string color)
		{
			std::multimap<std::string, std::string> ::iterator itr = mColorItems.find(color);

			while (itr != mColorItems.end())
			{
				if (itr->first != color)
				{
					break;
				}
				std::cout << itr->first << "," << itr->second << std::endl;
				itr++;
			}
		}
	};
}