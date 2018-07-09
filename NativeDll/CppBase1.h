#pragma once 

#include <string>
#include "CppBaseVirtual.h"

using namespace std;

namespace NativeDll
{
	// virtual 代表 CppBaseVirtual 是 CppBase1 的虚基类（虚基类是在声明派生类时，指定继承方式时声明的）
	class CppBase1 : virtual public CppBaseVirtual
	{

	protected:
		string Name;
		float Salary;

	public:
		CppBase1(int number, string name, float salary);

	};
}
