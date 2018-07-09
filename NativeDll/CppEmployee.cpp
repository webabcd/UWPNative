/*
 * CppEmployee 类
 */

#include "pch.h" 
#include "CppEmployee.h" 
#include "cppHelper.h"

using namespace NativeDll;

// “::”是作用域限定符（field qualifier）
string CppEmployee::Show()
{
	return int2string(Number) + " " + Name;
}

string CppEmployee::ToString()
{
	return int2string(Number) + " " + Name;
}

// 无参数的构造函数
CppEmployee::CppEmployee()
{
	Number = 888;
	Name = "webabcd";
}

// 有参数的构造函数，可以在声明中为参数指定默认值
CppEmployee::CppEmployee(int number, string name)
{
	Number = number;
	Name = name;
}

// 可以通过下面这种简单的方式，将构造函数中的参数值赋值给对象的变量
CppEmployee::CppEmployee(int number, string name, bool isMale) :Number(number), Name(name), IsMale(isMale)
{

}

CppEmployee::~CppEmployee()
{

}