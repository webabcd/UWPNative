/*
 * 引用类型
 *
 * 引用也可以称之为“别名”
 *
 * 注：
 * 1、声明引用时，必须同时初始化
 * 2、被引用的对象必须已经分配了空间
 * 3、被引用的对象不能为地址，即指针变量、数组变量等不能被引用
 */

#include "pch.h" 
#include "CppReference.h" 

using namespace NativeDll;

void reference_demo1();
void reference_demo2();
void reference_demo3();

string CppReference::Demo()
{
	// 引用的用法
	reference_demo1();

	// 引用和指针的区别
	reference_demo2();

	// “引用”也可以作为函数的返回值
	reference_demo3();


	return "看代码及注释吧";
}



// 引用的用法
void reference_demo1()
{
	int a1, a2 = 10;
	// &b - 代表定义一个名为 b 的引用。此处的“&”是类型说明符，表示 b 是一个引用
	// 声明了一个引用，则必须同时为其初始化
	int &b = a1; // b 是 a1 的引用，即 b 是 a1 的别名
	
	b = a2; // a1 和 b 都等于 10
	a1 = 100; // a1 和 b 都等于 100
	b = 1000; // a1 和 b 都等于 1000
}



// 引用和指针的区别
void reference_demo2()
{
	int m = 1;
	int n = 2;

	int *x = &m;
	int *y = &n;

	int &s = m;
	int &t = n;

	void my_swap(int *i, int *j); // 通过指针，交换两个整型
	void my_swap(int &i, int &j); // 通过引用，交换两个整型

	my_swap(x, y); // 调用 void my_swap(int *i, int *j); 结果：m=2,n=1
	my_swap(s, t); // 调用 void my_swap(int &i, int &j); 结果：m=1,n=2
	my_swap(m, n); // 调用 void my_swap(int &i, int &j); 结果：m=2,n=1
}

// 通过指针，交换两个整型
void my_swap(int *i, int *j)
{
	// 形参是实参的副本，这里会将指针复制一份出来，函数调用结束后立即释放

	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

// 通过引用，交换两个整型
void my_swap(int &i, int &j)
{
	// 如果采用“引用”的方式，i 和 j 其实就是对应的那两个实参本身

	int temp;
	temp = i;
	i = j;
	j = temp;
}



// “引用”也可以作为函数的返回值
int &reference_function();
int reference_i = 0;
void reference_demo3()
{
	reference_function() = 999;

	// 此时 reference_i 的值为 999
}

int &reference_function()
{
	return reference_i;
}