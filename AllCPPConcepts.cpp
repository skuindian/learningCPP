// AllCPPConcepts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "concepts\CopyConstructor.h"
#include "concepts\VirtualFunction.h"
#include "concepts\FriendFunction.h"
#include "concepts\OperatorOverloading.h"
#include "concepts\QuickTest.h"
#include "concepts\VolatileKeyword.h"
#include "concepts\CallbackFunction.h"
#include "concepts\TemplateFunction.h"
#include "concepts\RadicalRepresentation.h"
#include "concepts\LambdaFunction.h"
#include "concepts\DSLinkList.h"
#include "concepts\VariousAlgoImplementation.h"
#include "concepts\RecursiveFunction.h"
#include "concepts\BinarySearchTree.h"
#include "concepts\BinaryTree.h"
#include "concepts\Palindrome.h"

int main()
{
	int option;

	do
	{
		std::cout << std::endl;
		std::cout << "****************************************************************************" << std::endl;
		std::cout << "1) Implementation for Copy Constructor." << std::endl;
		std::cout << "2) Implementation for Virtual Function." << std::endl;
		std::cout << "3) Implementation for Friend Function." << std::endl;
		std::cout << "4) Implementation for Operator Overloading." << std::endl;
		std::cout << "5) Quick Test." << std::endl;
		std::cout << "6) Volatile Variable." << std::endl;
		std::cout << "7) Callback Function." << std::endl;
		std::cout << "8) Template Function." << std::endl;
		std::cout << "9) Redical Represention." << std::endl;
		std::cout << "10) Lamda Function." << std::endl;
		std::cout << "11) List Operation." << std::endl;
		std::cout << "12) Algo Implementation." << std::endl;
		std::cout << "13) Recursive Function." << std::endl;
		std::cout << "14) Binary Search Tree." << std::endl;
		std::cout << "15) Binary Tree." << std::endl;
		std::cout << "16) Check palindrome." << std::endl;
		std::cout << "100) Exit from program" << std::endl;
		std::cout << "****************************************************************************" << std::endl;
		std::cout << "Please select any of the option above:" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			std::cout << "Implementation for Copy Constructor..." << std::endl;
			CopyConstructor::BaseClass bClass1;
			bClass1.setVal(10);
			CopyConstructor::BaseClass bClass2 = bClass1;
			std::cout << "Val is:" << bClass2.getVal() << std::endl;
		}
		break;
		case 2:
		{
			std::cout << "Implementation for Virtual Function..." << std::endl;
			VirtualFuncation::BaseClass *baseClass = new VirtualFuncation::BaseClass("Base Class");
			VirtualFuncation::DerivedClass *derivedClass = new VirtualFuncation::DerivedClass("Derived Class");

			//Print Value
			std::cout << baseClass->getName() << std::endl;
			std::cout << derivedClass->getName() << std::endl;

			//Virtual Concept
			VirtualFuncation::BaseClass *vClass = new VirtualFuncation::DerivedClass("Virtual Class");
			std::cout << vClass->getName() << std::endl;

			//Test Memory - TODO			
			VirtualFuncation::BaseClass *memClass = new VirtualFuncation::BaseClass("TEST");
			std::cout << "TODO - Check Memory Implementation Pending..." << std::endl;
			//for (int index = 1; index <= 10; index++)
			{
				//char newChar = index + '\0';
				//std::string newStr = std::string("TEST-") + std::string(1, newChar);
				//memClass->setName(const_cast<char *>(newStr.c_str()));
				//memClass->setName("TEST-MEMORY");
				//std::cout << memClass->getName() << std::endl;
			}
		}
		break;
		case 3:
		{
			using namespace FriendFunction;

			std::cout << "Implementation for Friend Function..." << std::endl;
			BaseClass baseClass(10);
			DerivedClass derivedClass(20);

			compute(baseClass, derivedClass);
		}
		break;
		case 4:
		{
			std::cout << "Implementation for Operator Overloading..." << std::endl;
			OperatorOverloading::BaseClass baseClass1(10);
			OperatorOverloading::BaseClass baseClass2(0);
			OperatorOverloading::BaseClass baseClass3;
			OperatorOverloading::BaseClass baseClass4 = baseClass1 / baseClass2;

			baseClass3 = baseClass1 / baseClass2;

			std::cout << "Result-01:" << baseClass3.getVal() << std::endl;
			std::cout << "Result-02:" << baseClass4.getVal() << std::endl;
		}
		break;
		case 5:
		{
			QuickTest::QuickTest::testFunction();
		}
		break;
		case 6:
		{
			VolatileKeyword::testFunction();
		}
		break;
		case 7:
		{
			using namespace CallbackFunction;

			MyClass mClass;
			//int (*ptr)() = &mClass.handleTimeout;
			//MyTimerClass::startTimer(*ptr, 10);
			
			MyTimerClass::startTimer(&mClass.handleTimeout, 10000);
			MyTimerClass::stopTimer();
		}
		break;
		case 8:
		{
			using namespace TemplateFunction;

			auto val1 = 0.0f;
			auto val2 = 0.0f;

			std::cout << "Enter first value:";
			std::cin >> val1;
			std::cout << "Enter second value:";
			std::cin >> val2;

			std::cout << sum<float>(val1, val2) << std::endl;
		}
		break;
		case 9:
		{
			using namespace RadicalRepresentation;

			int number, redix;

			std::cout << "Enter Number:";
			std::cin >> number;
			std::cout << "Enter Base:";
			std::cin >> redix;
			std::cout << std::endl;

			std::cout << "Conversion Number by Base is:" << converter(number, redix) << std::endl;
			std::cout << "Binary count for 1 in number is:iterate logic:" << findBinaryNumber(number, 1) << std::endl;
			std::cout << "Binary count for 1 in number is:Bitwise logic:" << findBinaryNumberByBitwise(number, 1) << std::endl;
			std::cout << "(-ve) of the number:" << negativeNumber(number) << std::endl;
		}
		break;
		case 10:
		{
			using namespace LambdaFunction;

			std::vector <int> val = {10, 20, 30, 40, 50};

			std::cout << "Without lambda:" << std::endl;
			func(val);
			std::cout << "With lambda:" << std::endl;
			printVector(val);
		}
		break;
		case 11:
		{
			using namespace NDSLinkList;
			
			DSLinkList<int> *recordList = new DSLinkList<int>;

			int elements[] = { 10, 20, 30, 40, 50, 60 };

			bool retStatus = addNode(&recordList, elements, sizeof(elements)/sizeof(int));

			std::cout << "\nNodes in the lists are:" << std::endl;
			//Display List Nodes
			display(recordList);

			std::cout << "\n\nReverse lists are:" << std::endl;
			//Reverse List
			reverse(&recordList);

			//Display List Nodes
			display(recordList);

			std::cout << "\n\nNodes count in the lists are:" << count(recordList) << std::endl;

			std::cout << "\nNodes in the lists are:" << std::endl;
			//Display List Nodes
			display(recordList);

			std::cout << "\n\nAdding loop in the list" << std::endl;
			std::cout << "Enter the position between 1 to " << sizeof(elements) / sizeof(int) << ":";
			int position = 0;
			std::cin >> position;
			if (position > 1 && position < sizeof(elements) / sizeof(int))
			{
				addLoop(recordList, position);
			}
			else
			{
				std::cout << "Invalid position selected." << std::endl;
			}

			std::cout << "\nNodes are in loop:";
			//Display List Nodes
			bool status = isloopInNode(recordList);
			if (status)
			{
				std::cout << "true";
			}
			else
			{
				std::cout << "false";

			}
		}
		break;
		case 12:
		{
			using namespace NVariousAlgoImplementation;

			//Problem - 01
			//solveProblem01(1, 7, 12);
			
			//Problem - 02
			int src[] = { 1, 3, 5, 4, 1, 4, 5, 6, 1, 2, 4, 7, 9, 2, 1, 2, 3, 6, 9, 8};
			int size = sizeof(src) / sizeof(int);
			//solveProblem02_01(src, size);
			solveProblem02_02(src, size);

			std::cout << "\nSorted Array is:" << std::endl;
			for (int index = 0; index < size; index++)
			{
				std::cout << src[index] << " ";
			}
		}
		break;
		case 13:
		{
			using namespace NRecursiveFunction;

			int sensorA[] = { 10, 12, -20, 56, 14 };
			int sensorB[] = { 18, 16, -20, 56, 10 };

			int val = getAbs(sensorA, sensorB, sizeof(sensorA) / sizeof(int));

			std::cout << val;
		}
		break;
		case 14:
		{
			using namespace NDSBinarySearchTree;

			BinarySearchTree binarySearchTree;
						
			int elements[] = { 50, 60, 30, 40, 70, 10, 55, 5, 80, 75, 65 };

			struct TreeNode *BST = new TreeNode;
			binarySearchTree.createTree(&BST, elements, sizeof(elements) / sizeof(int));

			std::cout << "Elements in the binary tree are:" << std::endl;

			//Display List Nodes
			binarySearchTree.display(BST);
		}
		break;
		case 15:
		{
			using namespace NDSBinaryTree;

			BinaryTree binaryTree;

			struct TreeNode *BT = new TreeNode;

			int elements[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

			binaryTree.createTree(&BT, elements, sizeof(elements) / sizeof(int));

			std::cout << "Elements in the binary tree are:" << std::endl;

			//Display List Nodes
			binaryTree.display(BT);
		}
		break;
		case 16:
		{
			using namespace NPalindrome;
			
			auto number = 0;
			std::cout << "Please enter the number:";
			std::cin >> number;

			if (checkNumberPalindrome(number))
			{
				std::cout << "\nNumber is palindrome.";
			}
			else
			{
				std::cout << "\nNumber is not palindrome.";
			}

			char str[1024];
			std::cout << "Please enter the string:";
			std::cin >> str;

			std::cout << "\nEntered string is:";
			std::cout << str;

			if (checkStringPalindromeWithoutRev(str))
			{
				std::cout << "\nString is palindrome.";
			}
			else
			{
				std::cout << "\nString is not palindrome.";
			}

		}
		break;
		default:
		{
			std::cout << "No valid option selected" << std::endl;
			break;
		}
		}
	} while (option != 100);
	
	return 0;
}

