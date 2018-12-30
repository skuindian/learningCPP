#pragma once

namespace NDPSingleton
{
	class SingletonClass
	{
	private:
		static SingletonClass *mSingletonClass;

		SingletonClass()
		{
			std::cout << "Inside Default Constructor" << std::endl;
		}
		
		SingletonClass(const SingletonClass&)
		{
			std::cout << "Inside Copy Constructor" << std::endl;
		}

		SingletonClass& operator=(const SingletonClass&)
		{
			std::cout << "Inside Copy Operator =" << std::endl;
		}

		SingletonClass& operator=(const SingletonClass*)
		{
			std::cout << "Inside Copy Operator =" << std::endl;
		}

		SingletonClass(SingletonClass&&)
		{
			std::cout << "Inside Move Constructor" << std::endl;
		}

		SingletonClass&& operator=(SingletonClass&&)
		{
			std::cout << "Inside Move Operator =" << std::endl;
		}

		~SingletonClass() { /* destructor */ }
	public:

		static SingletonClass *getInstance()
		{
			if (nullptr == mSingletonClass)
			{
				mSingletonClass = new SingletonClass();
			}

			return mSingletonClass;
		}

		void doTask()
		{
			std::cout << "Inside method doTask()" << std::endl;
		}
	};
}