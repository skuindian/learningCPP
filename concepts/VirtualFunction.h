#pragma once

namespace VirtualFuncation
{
	class BaseClass
	{
		char *name = NULL;
	public:
		BaseClass()
		{
		}

		BaseClass(char *pName)
		{
			int count = 0;
			std::cout << "START" << std::endl;
			while (*pName != '\0')
			{
				std::cout << *pName;
				pName++;
				count++;
			}
			std::cout << "" << std::endl;
			std::cout << "END" << std::endl;
			name = new char[count + 1];
			pName = pName - count;
			memcpy(name, pName, sizeof(char) * count);
			name[count] = '\0';
		}

		void setName(char *pName)
		{
			int count = 0;
			std::cout << "START" << std::endl;
			while (*pName != '\0')
			{
				std::cout << *pName;
				pName++;
				count++;
			}
			std::cout << "" << std::endl;
			std::cout << "END" << std::endl;

			if (name != NULL)
			{
				std::cout << "DELETING MEMORY" << std::endl;
				char *newChar = new char[count];
				delete name;
				name = NULL;
				name = newChar;
			}
			else
			{
				name = new char[count];
			}
			pName = pName - count;
			name = pName;
		}

		virtual char* getName()
		{
			std::cout << "Inside BaseClass" << std::endl;
			return name;
		}
	};

	class DerivedClass: public BaseClass
	{
		char *name;
	public:
		DerivedClass(char *name)
		{
			this->name = new char[10];
			this->name = name;
		}
		char* getName()
		{
			std::cout << "Inside DerivedClass" << std::endl;
			return name;
		}
	};
}