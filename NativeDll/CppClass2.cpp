/*
 * this 指针, 对象数组, 对象和指针, const 对象,  const 指针和指向 const 对象的指针, const 对象的引用
 */

#include "pch.h" 
#include "CppClass2.h" 
#include "CppEmployee.h" 

using namespace NativeDll;

void cppclass2_demo1();
void cppclass2_demo2();
void cppclass2_demo3();
void cppclass2_demo4();
void cppclass2_demo5();

string CppClass2::Demo()
{
	// 什么是 this 指针：
	// 在每一个成员函数中都包含一个特殊的指针，即 this 指针。它是指向本类对象的指针，它的值是当前被调用的成员函数所在的对象的起始地址
	this->Name = "abc";
	string name = (*this).Name;


	// 对象数组
	cppclass2_demo1();

	// 对象和指针
	cppclass2_demo2();

	// const 对象
	cppclass2_demo3();

	// const 指针和指向 const 对象的指针
	cppclass2_demo4();

	// const 对象的引用
	cppclass2_demo5();


	return "看代码及注释吧";
}



// 对象数组
void cppclass2_demo1()
{
	// 对象数组
	CppEmployee employees[3] =
	{
		CppEmployee(1, "name1"),
		CppEmployee(2, "name2"),
		CppEmployee(3, "name3")
	};

	// 数组名 employees 就是该数组的首地址
	employees->Show(); // 1 name1
}



// 对象和指针
void cppclass2_demo2()
{
	CppEmployee employee(1, "webabcd"); 


	// 指向对象的指针
	CppEmployee *p1 = &employee;
	p1->Salary = 1000;


	// 指向对象中的指定属性的指针
	float *p2 = &employee.Salary; // . 的优先级高


	// 函数指针（指向函数的指针）
	string (CppEmployee::*p3)(); // 定义一个函数指针。此函数为 CppEmployee 类中的一个 public 函数，其无参数，返回值为 string 类型
	p3 = &CppEmployee::Show; // 使 p3 指向 CppEmployee 类中的 public 函数 Show
	string result = (employee.*p3)(); // 调用对象 employee 中 p3 所指的函数

	string(CppEmployee::*p4)() = &CppEmployee::Show;
	result = (employee.*p4)(); // 1 webabcd
}



namespace NativeDll
{
	class CppEmployeeConst
	{

	public: 
		float Salary;
		int Age;
		mutable int Num; // mutable 属性，即使对象是 const 对象的话，也可以设置其 mutable 属性
		const string Name; // const 数据成员
		const boolean IsMale; // const 数据成员

		string Show() const // const 成员函数（注意 const 写在后面）
		{
			// const 函数不能调用非 const 函数
			// return this->ToString();

			return "abc";
		}

		string ToString()
		{
			return "abc";
		}

		// 必须提供一个构造函数，用以初始化所有 const 数据成员
		CppEmployeeConst(string name) :Name(name), IsMale(true)
		{ 
			this->Age = 35;
		}
	};
}

// const 对象
void cppclass2_demo3()
{
	// 实例化一个非 const 对象
	CppEmployeeConst employee("webabcd");
	// 不能修改对象中的 const 属性
	// employee.IsMale = true;



	// 实例化一个 const 对象
	// CppEmployeeConst const employeeConst;
	const CppEmployeeConst employeeConst("webabcd");

	// 可以获取 const 对象中的 const 属性和非 const 属性
	string name = employee.Name;
	int age = employee.Age;

	// 不能设置 const 对象中的 const 属性和非 const 属性
	// employee.Salary = 100;
	// employee.Name = "wanglei";

	// 可以设置 const 对象中的 mutable 属性
	employee.Num = 88;

	// 可以调用 const 对象中的 const 函数，不能调用非 const 函数
	employee.Show();
	// employee.ToString();
}



// const 指针和指向 const 对象的指针
void cppclass2_demo4()
{
	CppEmployee employee(1, "webabcd");
	CppEmployee employee2(1, "webabcd");


	// const 指针：指针始终指向同一个对象（指针是 const 的）
	CppEmployee *const p1 = &employee;
	// p1 = &employee2; // 编译错误，因为指针是 const 的，不能对其赋值


	// 指向 const 对象的指针（所指的对象是 const 的）
	const CppEmployee *p2 = &employee;
	// p2->Salary = 100; // 编译错误，因为所指的对象是 const 的，不能对其属性赋值


	// 当使用指针的方式传参时，如果不希望在函数中修改其所指的对象，则可以这么做
	void cppclass2_function1(const CppEmployee *p);
	cppclass2_function1(&employee);
}

void cppclass2_function1(const CppEmployee *p)
{
	// 不能在此函数中修改 p 所指对象
	// p->Salary = 100;
}



// const 对象的引用
void cppclass2_demo5()
{
	CppEmployee employee(1, "webabcd");
	CppEmployee employee2(1, "webabcd");


	// const 对象的引用（被引用的对象是 const 的）
	const CppEmployee &r = employee;
	// r.Salary = 100; // 编译错误，因为被引用的对象是 const 的，不能对其属性赋值


	// 当使用引用的方式传参时，如果不希望在函数中修改其引用的对象，则可以这么做
	void cppclass2_function2(const CppEmployee &r);
	cppclass2_function2(r);
	cppclass2_function2(employee);
}

void cppclass2_function2(const CppEmployee &r)
{
	// 不能在此函数中修改 r 所引用的对象
	// r.Salary = 100;
}