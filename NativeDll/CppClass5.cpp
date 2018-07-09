/*
 * 继承, 组合, 派生类的构造函数和析构函数, 基类与派生类的转换, 子对象的实例化, 基类成员的隐藏（派生类成员覆盖基类成员）
 */

#include "pch.h" 
#include "CppClass5.h" 
#include "CppTiger.h"

using namespace NativeDll;

string cppclass5_demo1();
string cppclass5_demo2();
void cppclass5_demo3();

string CppClass5::Demo()
{
	string r1 = cppclass5_demo1();
	string r2 = cppclass5_demo2();
	string result = r1 + "\n" + r2;

	// 基类与派生类的转换
	cppclass5_demo3();

	return result;
}


string cppclass5_demo1()
{
	// 此处演示了派生类的构造函数
	CppTiger tiger(100, "老虎", "大猫");

	// 此处演示了基类成员的隐藏（派生类成员覆盖基类成员）
	string result = tiger.Show(); // tiger: 老虎, employee: 888 webabcd, animal: 100 老虎

	return result;
}


string cppclass5_demo2()
{
	// 此处演示了派生类的构造函数，以及同时实例化子对象
	CppTiger tiger2(100, "老虎", 200, "wanglei");

	// 此处演示了基类成员的隐藏（派生类成员覆盖基类成员）
	string result = tiger2.Show(); // tiger: 老虎, employee: 200 wanglei, animal: 100 老虎

	return result;
}


// 基类与派生类的转换
void cppclass5_demo3()
{
	// 派生类对象可以赋值给基类对象（反之不可），基类对象无法使用派生类对象的特性
	CppTiger tiger(100, "老虎", 200, "wanglei");
	CppAnimal animal = tiger;
	// 调用的是基类的 Show() 函数（但是数据成员是通过 CppTiger 实例化而来的）
	string result = animal.Show(); // animal: 100 老虎


	// 指向基类对象的指针，也可以指向派生类对象（反之不可），但是无法使用派生类对象的特性
	CppAnimal animal2(100);
	CppAnimal *animal2Pointer = &animal2;
	CppTiger tiger2(200, "老虎", 300, "wanglei");
	animal2Pointer = &tiger2;
	// 调用的是基类的 Show() 函数（但是数据成员是通过 CppTiger 实例化而来的）
	string result2 = animal2Pointer->Show(); // animal: 200 老虎
}