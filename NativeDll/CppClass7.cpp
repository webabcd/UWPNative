/*
 * 虚函数
 */

#include "pch.h" 
#include "CppClass7.h" 
#include "CppChild.h"

using namespace NativeDll;

void cppclass7_demo1();
void cppclass7_demo2();

string CppClass7::Demo()
{
	// 虚函数
	cppclass7_demo1();

	// virtual 的析构函数
	cppclass7_demo2();


	return "看代码及注释吧";
}



// 虚函数
void cppclass7_demo1()
{
	// 不使用虚函数的示例：参见 CppClass5.cpp 中的“基类与派生类的转换”

	// 以下演示了如何使用虚基类
	CppHuman human("webabcd");
	CppChild child("diandian");

	// 指针指向基类，调用虚函数后执行的是基类的虚函数
	CppHuman *humanPointer = &human;
	string result = humanPointer->Show(); // human: webabcd

	// 指向基类的指针改为指向派生类，调用虚函数后执行的是派生类的虚函数
	humanPointer = &child;
	result = humanPointer->Show(); // child: diandian


	// 像上面这种方式是在程序运行阶段把虚函数和类对象“绑定”在一起的，因此此过程称为动态关联（dynamic binding）或滞后关联（late binding），其属于动态多态性
	// 如果使用了虚函数，则编译器会为该类构造一个虚函数表（virtual function table，简称 vtable），它是一个指针数组，存放每个虚函数的入口地址，据此可做静态关联和动态关联
}



// virtual 的析构函数
void cppclass7_demo2()
{
	// 一般来说，清理派生类时，会先调用派生类的析构函数，然后调用基类的析构函数
	// 但是下面这种情况例外
	CppHuman *pt = new CppChild("diandian");
	delete pt;
	// 此时，如果基类的析构函数不是 virtual 的，则只会执行基类的析构函数
	// 此时，如果基类的析构函数是 virtual 的，则会先执行派生类的析构函数，再执行基类的析构函数
	// 所以，最好把基类的析构函数声明为虚函数（其会使所有派生类的析构函数都自动变为虚函数），以避免清理不彻底
}