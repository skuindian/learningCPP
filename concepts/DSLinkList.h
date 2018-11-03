#pragma once

namespace NDSLinkList
{
	template <typename ItemType>
	class DSLinkList
	{
	public:
		ItemType number;
		DSLinkList<ItemType> *link;
	};
	
	template <typename ItemType>
	bool addNode(DSLinkList<ItemType> **linkList, const ItemType (&item)[6], int number)
	{
		DSLinkList<ItemType> *dummyNode = nullptr;
		for (int index = 0; index < number; index++)
		{
			if (dummyNode == nullptr)
			{
				dummyNode = *linkList;
				dummyNode->number = item[index];
				dummyNode->link = nullptr;
			}
			else
			{			
				DSLinkList<ItemType> *nextNode = new DSLinkList<ItemType>;;
				nextNode->number = item[index];
				nextNode->link = nullptr;

				dummyNode->link = nextNode;
				dummyNode = dummyNode->link;
			}
		}
		
		return true;
	}

	template <typename ItemType>
	void display(DSLinkList<ItemType> *linkList)
	{
		while (linkList != nullptr)
		{
			std::cout << linkList->number;
			if(linkList->link != nullptr)
				std::cout << "->";
			linkList = linkList->link;
		}
	}

	template<typename ItemType>
	void reverse(DSLinkList<ItemType> **linkList)
	{
		DSLinkList<ItemType> *prev = nullptr;
		DSLinkList<ItemType> *curr = *linkList;
		DSLinkList<ItemType> *next = nullptr;

		while (curr != nullptr)
		{
			next = curr->link;
			curr->link = prev;
			prev = curr;
			curr = next;
		}

		*linkList = prev;
	}

	template<typename ItemType>
	int count(DSLinkList<ItemType> *linkList)
	{
		int count = 0;

		while (linkList != nullptr)
		{
			count++;
			linkList = linkList->link;
		}

		return count;
	}

	template <typename ItemType>
	void addLoop(DSLinkList<ItemType> *linkList, int position)
	{
		int pos = 1;

		while (linkList != nullptr)
		{
			if (pos == position)
			{
				linkList->link = linkList;
				break;
			}

			pos++;

			linkList = linkList->link;
		}
	}

	template <typename ItemType>
	bool isloopInNode(DSLinkList<ItemType> *linkList)
	{
		DSLinkList<ItemType> *tLinkList = linkList->link;
		DSLinkList<ItemType> *pLinkList = linkList;

		while (pLinkList !=nullptr && tLinkList != nullptr)
		{
			if (tLinkList == pLinkList)
			{
				return true;
			}

			if (tLinkList->link != nullptr)
			{
				tLinkList = tLinkList->link->link;
			}
			else
			{
				tLinkList = tLinkList->link;
			}
			pLinkList = pLinkList->link;
		}

		return false;
	}

	void understandAddresses()
	{
		int var = 10;
		int *addOfVar = &var;
		int **addAddOfVar = &addOfVar;

		std::cout << var << "\t" << &var << "\t" << addOfVar << "\t" << *addOfVar << "\t" << &addOfVar << "\t" << addAddOfVar
			<< "\t" << *addAddOfVar << "\t" << **addAddOfVar;
	}
}
