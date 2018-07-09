#pragma once 

#include <string>

using namespace std;

namespace NativeDll
{
	class CppEmployee
	{

		int Number; // 默认为 private

	private: // 以下都是 private 的
		string Name;
		bool IsMale;

	protected: // 以下都是 protected 的
		string ToString();

	public: // 以下都是 public 的
		float Salary;
		int Age;
		string Show();

		// 构造函数（constructor），不定义的话，编译时会自动生成一个默认的不做任何事情的无参数构造函数（如果指定为 private 的话就可以禁止直接实例化，一般做单例模式的话会这么做）
		// 另外：如果声明了带参数的构造函数，则不会自动生成默认的无参数构造函数
		CppEmployee();
		CppEmployee(int number, string name = "webabcd"); // 可以为构造函数中的参数指定默认值（参考：CppFunction1.cpp）
		CppEmployee(int number, string name, bool isMale);

		// 析构函数（destructor），对象被销毁时会调用，例如释放动态分配的内存等。不需要时也可以不定义，编译时会自动生成一个默认的不做任何事情的析构函数，析构函数的函数名与类名相同，前面有“~”
		~CppEmployee();

	private:
		// 注：在体内定义的成员函数，系统会自动将其作为 inline 函数处理（关于 inline 函数，参见：CppFunction2.cpp）
		void Temp()
		{
			int a = 100;
		}

		/*
		下面这个与上面那个一样
		inline void Temp()
		{
			int a = 100;
		}
		*/

	};
}
