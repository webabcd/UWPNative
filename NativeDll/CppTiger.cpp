/*
 * 用于派生类的演示
 */

#include "pch.h" 
#include "CppTiger.h" 
#include "cppHelper.h"

using namespace NativeDll;

// 在派生类的构造函数中调用基类的构造函数（注：在无虚基类的情况下，派生类的构造函数中只需负责对其直接基类初始化）
CppTiger::CppTiger(int number) :CppAnimal(number)
{

}

// 在派生类的构造函数中调用基类的构造函数，初始化派生类的私有成员
CppTiger::CppTiger(int number, string name, string nickName) :CppAnimal(number), NickName(nickName)
{
	// 初始化基类的保护成员
	Name = name;
}

// 在构造函数中，用简单的方式实例化子对象（本例实例化了 employee 对象）
CppTiger::CppTiger(int tigerNumber, string tigerName, int employeeNumber, string employeeName) :CppAnimal(tigerNumber), employee(employeeNumber, employeeName)
{
	// 如果用此种方式实例化子对象，则其实子对象会被实例化 2 次（声明时的 CppEmployee employee; 会被实例化一次，此处又会被实例化一次）
	// this->employee = CppEmployee(employeeNumber, employeeName);

	Name = tigerName;
}

// 我是 CppTiger 的 Show() 函数，由于与 CppAnimal 中的 Show() 函数同名且参数相同，所以 CppAnimal 中的 Show() 函数会被隐藏掉。也可以说 CppTiger 的 Show() 函数覆盖了 CppAnimal 中的 Show() 函数
string CppTiger::Show()
{
	// 在派生类中调用基类成员的话，需要通过“::”来实现
	// 本例中如果要调用基类的 Show() 的话，就这么写 CppAnimal::Show()
	// 如果直接调用 Show() 的话就死循环了

	return "tiger: " + Name + ", employee: " + employee.Show() + ", " + CppAnimal::Show();
}
