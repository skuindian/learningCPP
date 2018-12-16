#pragma once

namespace TemplateFunction
{
	template<class C, class P>
	bool IsDerivedFrom(C cObj, P pObj)
	{
		std::cout << "Inside IsDerivedFrom" << std::endl;

		std::cout << typeid(cObj).name() << std::endl;
		std::cout << typeid(pObj).name() << std::endl;

		P *p = dynamic_cast<P *>(&cObj);

		if (p == nullptr)
		{
			std::cout << "C object is not derived from P object." << std::endl;
			return false;
		}
		else
		{
			std::cout << "C object is derived from P object." << std::endl;
			return true;
		}
	}

	class PClass
	{
	public:
		PClass()
		{
			std::cout << "Inside PClass" << std::endl;
		}
	};

	class CClass : public PClass
	{
	public:
		CClass()
		{
			std::cout << "Inside CClass" << std::endl;
		}

	};
}