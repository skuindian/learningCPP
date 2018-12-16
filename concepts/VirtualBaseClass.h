#pragma once

namespace NVirtualBaseClass
{
	/*
	 *		  A 
	 *		/   \
	 *		B    C
	 *		\	/
	 *		  D
	 */

	class A
	{
	public:
		A()
		{
			std::cout << "Inside A()" << std::endl;
		}

		void display()
		{
			std::cout << "Inside A::display()" << std::endl;
		}

		virtual void show() = 0;
	};

	class B: virtual public A //Needed to call A constructor only once
	{
	public:
		B()
		{
			std::cout << "Inside B()" << std::endl;
		}

		void display()
		{
			std::cout << "Inside B::display()" << std::endl;
		}

		virtual void show()
		{
			std::cout << "Inside B::show()" << std::endl;
		}
	};

	class C: virtual public A //Needed to call A constructor only once
	{
	public:
		C()
		{
			std::cout << "Inside C()" << std::endl;
		}

		void display()
		{
			std::cout << "Inside C::display()" << std::endl;
		}

		virtual void show()
		{
			std::cout << "Inside C::show()" << std::endl;
		}
	};

	class D: public C, public B
	{
	public:
		D()
		{
			std::cout << "Inside D()" << std::endl;
		}

		/*
		void display()
		{
			std::cout << "Inside D::display()" << std::endl;
		}*/

		void show()
		{
			std::cout << "Inside D::show()" << std::endl;
		}
	};
}