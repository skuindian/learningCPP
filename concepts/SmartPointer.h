#pragma once

namespace NSmartPointer
{
	class ValueContainer
	{
		int mValue;
	public:
		ValueContainer(int value)
		{
			mValue = value;
			std::cout << "Constructing ValueContainer" << std::endl;
		}

		~ValueContainer()
		{
			std::cout << "Deleting ValueContainer" << std::endl;
		}

		int getValue()
		{
			return mValue;
		}
	};

	int implementAutoPointer()
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "Function: implementAutoPointer" << std::endl;
		std::cout << "---------------------------------------" << std::endl;

		int number = 10;
		std::auto_ptr<ValueContainer> pOneValueContainer(new ValueContainer(number));
		std::cout << "Address Of One:" << pOneValueContainer.get() << std::endl;
		std::cout << "Value Of One:" << pOneValueContainer->getValue() << std::endl;

		/*
		 * In both the cases auto_ptr will leave its owner ship
		 */
		std::auto_ptr<ValueContainer> pSecondValueContainer(pOneValueContainer);
		//or
		//std::auto_ptr<ValueContainer> pSecondValueContainer = pOneValueContainer;

		std::cout << "Address Of One:" << pOneValueContainer.get() << std::endl;
		//std::cout << "Value Of One:" << pOneValueContainer->getValue() << std::endl;
		std::cout << "Address Of Two:" << pSecondValueContainer.get() << std::endl;
		std::cout << "Value Of Two:" << pSecondValueContainer->getValue() << std::endl;
		std::cout << "Class Name:" << typeid(ValueContainer).name() << std::endl;

		return 0;
	}

	int implementUniquePointer()
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "Function: implementUniquePointer" << std::endl;
		std::cout << "---------------------------------------" << std::endl;

		int number = 20;
		std::unique_ptr<ValueContainer> pOneValueContainer(new ValueContainer(number));

		/*
		 * In both the cases error will be populate
		 * By using std::move the ownership can be transfer for the unique pointer
		 */
		//std::unique_ptr<ValueContainer> pSecondValueContainer(pOneValueContainer);
		//or
		//std::unique_ptr<ValueContainer> pSecondValueContainer = pOneValueContainer;
		std::unique_ptr<ValueContainer> pSecondValueContainer = std::move(pOneValueContainer);

		//std::cout << "Address Of One:" << pOneValueContainer.get() << std::endl;
		//std::cout << "Value Of One:" << pOneValueContainer->getValue() << std::endl;
		std::cout << "Address Of Two:" << pSecondValueContainer.get() << std::endl;
		std::cout << "Value Of Two:" << pSecondValueContainer->getValue() << std::endl;
		
		return 0;
	}
}