/*
 * 对象的动态创建和释放, 对象的赋值和复制, 静态属性和静态函数, 类模板
 */

#include "pch.h" 
#include "CppClass3.h" 
#include "CppEmployee.h"

using namespace NativeDll;

void cppclass3_demo1();
void cppclass3_demo2();
void cppclass3_demo3();
void cppclass3_demo4();

string CppClass3::Demo()
{
	// 对象的动态创建和释放
	cppclass3_demo1();

	// 对象的赋值和复制
	cppclass3_demo2();

	// 静态属性和静态函数
	cppclass3_demo3();

	// 类模板
	cppclass3_demo4();

	return "看代码及注释吧";
}



// 对象的动态创建和释放
void cppclass3_demo1()
{
	// 动态创建对象：new 一个对象，返回的是指向这个对象的指针（如果失败则返回值为 0, 对应的宏 #define NULL 0）
	CppEmployee *employee1 = new CppEmployee;
	CppEmployee *employee2 = new CppEmployee(1, "webabcd");

	// 通过 delete pointer 来是释放内存
	delete employee1;
	delete employee2;
}



// 对象的赋值和复制
void cppclass3_demo2()
{
	CppEmployee employee1;
	CppEmployee employee2(1, "webabcd");

	// 对象的赋值：同类型的对象之间可以互相赋值。对象间的赋值就是对象属性的赋值；而他们调用的函数仍然是同一代码，不用赋值
	employee1 = employee2;


	// 对象的复制：从无到有地复制一个对象
	CppEmployee employee3(employee1);
	CppEmployee employee4 = employee1;


	/*
	 * 对象的赋值是对一个已经存在的对象赋值；对象的复制则是从无到有地创建一个新对象
	 */
}



// 用于演示静态属性和静态函数
namespace NativeDll
{
	class CppEmployeeStatic
	{

	public:
		static int Version; // 静态属性
		string Name;

		string Show()
		{
			return this->Name;
		}

		static int GetVersion() // 静态函数
		{
			// 静态函数中没有 this 指针
			return Version;
		}

		string ToString()
		{
			return "abc";
		}
	};
}

// 初始化静态属性（必须要初始化，不然编译出错）
int CppEmployeeStatic::Version = 10;

// 静态属性和静态函数的使用
void cppclass3_demo3()
{
	// 静态数据成员在程序启动时被分配空间（编译时会生成其分配方案），程序结束时释放空间

	CppEmployeeStatic employee;
	employee.Version = 100; // 支持用 对象. 的方式访问静态属性

	int version = CppEmployeeStatic::Version; // 支持用 类:: 的方式访问静态属性

	version = CppEmployeeStatic::GetVersion(); // 支持用 类:: 的方式访问静态函数
	version = employee.GetVersion(); // 支持用 对象. 的方式访问静态函数
}



// 用于演示类模板（类模板类似函数模板，函数模板参见：CppFunction2.cpp）
namespace NativeDll
{
	// template <class T1, class T2>

	// 声明一个模板，其有一个名为 T 的不定类型（虚拟类型）
	template <class T>

	// 使用了类模板的类就是模板类
	class CppClass3Compare
	{

	private:
		T x, y;

	public:
		CppClass3Compare(T a, T b)
		{
			x = a; 
			y = b;
		}

		T Max()
		{
			return (x > y) ? x : y;
		}

		T Min();

	};
}

// 注意：要在外面定义模板类的成员函数的话，要像下面这么写
template <class T>
T CppClass3Compare<T>::Min()
{
	return (x < y) ? x : y;
}

// 模板类的使用
void cppclass3_demo4()
{
	CppClass3Compare<int> cmp1(2, 14);
	int a = cmp1.Min(); // 2
	int b = cmp1.Max(); // 14

	CppClass3Compare<float> cmp2(6.26f, 3.14f);
	float f1 = cmp2.Min(); // 3.14
	float f2 = cmp2.Max(); // 6.26
}