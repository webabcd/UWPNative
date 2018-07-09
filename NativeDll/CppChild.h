#pragma once 

#include <string>
#include "CppHuman.h"

using namespace std;

namespace NativeDll
{
	class CppChild : public CppHuman
	{

	public: 
		// 由于基类 CppHuman 的 Show() 函数是虚函数，所以其所有直接或间接派生类中，如果声明了此函数则均为虚函数（virtual 可以省略）
		virtual string Show();

		CppChild(string name);

		~CppChild();

	};
}
