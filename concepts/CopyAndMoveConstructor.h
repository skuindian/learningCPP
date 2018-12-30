#pragma once

/*
https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=vs-2017
*/

namespace NCopyAndMoveConstructor
{
	class DummyClass
	{
		int mValue;

	public:
		DummyClass()
		{
			std::cout << "Inside default constructor" << std::endl;
			mValue = 10;
		}

		DummyClass(const DummyClass &obj)
		{
			std::cout << "Inside copy constructor" << std::endl;
			mValue = obj.mValue;
		}

		DummyClass(DummyClass &&obj)
		{
			std::cout << "Inside move constructor" << std::endl;
			*this = std::move(obj);
		}

		// Move assignment operator.
		DummyClass& operator=(DummyClass&& obj)
		{
			std::cout << "Inside move operator" << std::endl;

			if (this != &obj)
			{
				// Free the existing resource.
			}
			return *this;
		}

		const int getValue()
		{
			return mValue;
		}
	};
}