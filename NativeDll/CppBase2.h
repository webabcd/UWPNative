#pragma once 

#include <string>
#include "CppBaseVirtual.h"

using namespace std;

namespace NativeDll
{
	// virtual 代表 CppBaseVirtual 是 CppBase2 的虚基类（虚基类是在声明派生类时，指定继承方式时声明的）
	class CppBase2 : virtual CppBaseVirtual
	{

	protected:
		string Name;
		int Age;

	public:
		CppBase2(int number, string name, int age);

	};
}
