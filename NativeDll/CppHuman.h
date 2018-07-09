#pragma once 

#include <string>

using namespace std;

namespace NativeDll
{
	class CppHuman
	{

	protected:
		string Name;

	public:
		// 我是虚函数
		virtual string Show(); 
		
		// 我是纯虚函数（后面的“=0”只起形式上的作用，用于告诉编译器：“这是纯虚函数”）
		// 纯虚函数只有声明，没有定义，其具体的功能是留给派生类定义的
		// 凡是包含纯虚函数的类都是抽象类，抽象类是无法实例化的，因为纯虚函数是不能被调用的
		// virtual string Display() = 0; 

		CppHuman(string name);

		// 我是 virtual 的析构函数
		virtual ~CppHuman();

	};
}
