#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

namespace LambdaFunction
{
	using namespace std;

	//Problem
	void printVal(int val)
	{
		cout << "value:" << val << endl;
	}

	void func(std::vector<int>& v)
	{
		std::for_each(v.begin(), v.end(), printVal);
	}

	//Solution - lamda expression
	//[] -> Capture clause
	//() -> Parameter
	//{} -> Body
	void printVector(std::vector<int>& vector)
	{
		for_each(vector.begin(), vector.end(), [](int i)
		{
			cout << "value:" << i << endl;
		});
	}
}
