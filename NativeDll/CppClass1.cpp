/*
 * 类与对象
 */

#include "pch.h" 
#include "CppClass1.h" 
#include "CppEmployee.h"

using namespace NativeDll;

// “::”是作用域限定符（field qualifier）
string CppClass1::Demo()
{
	// 定义对象的方法 1：类声明的同时定义对象（此时也可以无类名）
	// 定义对象的方法 2：一般用如下的方法定义对象
	// class CppEmployee employee; // class 可以省去
	CppEmployee employee; // 实例化，同时分配内存空间（仅数据部分分配空间，函数部分不分配空间）

	// 可以访问 public 的属性或函数
	employee.Salary = 100.0f;
	employee.Show();

	// 对象的引用
	CppEmployee &employee2 = employee;
	employee2.Salary = 1000.0f;

	// 对象的指针
	CppEmployee *employee3 = &employee;
	employee3->Salary = 10000.0f;


	// 也可以这么实例化
	CppEmployee employee5(1, "webabcd"); // 实例化 1 次
	CppEmployee employee6 = { 1, "webabcd" }; // 实例化 1 次
	CppEmployee employee7 = CppEmployee(1, "webabcd"); // 实例化 2 次。CppEmployee employee7 会实例化一次，CppEmployee(1, "webabcd") 会实例化一次


	// 也可以这么实例化
	CppEmployee *employee8 = new CppEmployee(1, "webabcd"); // 实例化，并返回对象的地址
	employee8->Show();
	delete employee8;


	// 注：
	// 1、上面在 Demo 函数中实例化了很多内部对象，他们会按顺序一个一个地压入栈中，栈是 FILO 的，所以当 Demo 函数执行完毕，要销毁其内部对象时，是按照 FILO 的顺序调用析构函数的
	// 2、如果同一个类实例化了 n 个对象，则有 n 组同样大小的空间以存放 n 个对象中的数据成员。但是，不同对象都调用同一个函数代码段。


	return "看代码及注释吧";
}
