/*
 * 运算符重载, 自定义类型转换
 */

#include "pch.h" 
#include "CppOperator.h"
#include "cppHelper.h"
#include <iostream>

using namespace NativeDll;

void cppoperator_demo1();
void cppoperator_demo2();
void cppoperator_demo3();
void cppoperator_demo4();
void cppoperator_demo5();
void cppoperator_demo6();
void cppoperator_demo7();
void cppoperator_demo8();

string CppOperator::Demo()
{
	// 通过成员函数重载“+”运算符
	cppoperator_demo1();

	// 通过友元函数重载“*”运算符
	cppoperator_demo2();

	// 通过友元函数重载“==”运算符
	cppoperator_demo3();

	// 通过成员函数重载“前置++”运算符
	cppoperator_demo4();

	// 通过成员函数重载“后置++”运算符
	cppoperator_demo5();

	// 通过友元函数重载 ostream 的 <<
	cppoperator_demo6();

	// 类型转换函数（type conversion function），可以隐式转换或显式转换
	cppoperator_demo7();

	// 通过构造函数实现隐式转换
	cppoperator_demo8();


	// 运算符重载时，如果第一个操作数不是本类对象，则只能用 friend 的方式重载（此时不能用成员函数的方式重载）
	// 习惯来说：通过成员函数重载单目运算符；通过友元函数重载双目运算符
	// 不可以自定义新的运算符，只能重载已有运算符，其中不可重载的运算符有：“.”, “.*”, “sizeof()”, “::”, “?:”


	return "看代码及注释吧";
}



class CppOperatorComplex
{
private:
	string Name;
public:
	CppOperatorComplex() : Name("")
	{

	}
	CppOperatorComplex(string name) : Name(name)
	{

	}
	string ToString()
	{
		return Name;
	}

	// 通过成员函数重载“+”运算符（左边是本类对象，右边是指定的 CppOperatorComplex 对象）
	CppOperatorComplex operator+(CppOperatorComplex &coc);

	// 通过友元函数重载“*”运算符（左边是指定的 CppOperatorComplex 对象，右边是指定的 CppOperatorComplex 对象）
	friend CppOperatorComplex operator*(CppOperatorComplex &coc1, CppOperatorComplex &coc2); 
	// 通过友元函数重载“==”运算符（左边是指定的 string 对象，右边是指定的 CppOperatorComplex 对象）
	friend bool operator==(string &name, CppOperatorComplex &coc);

	// 通过成员函数重载“前置++”运算符
	CppOperatorComplex operator++();
	// 通过成员函数重载“后置++”运算符（这里需要加一个 int 类型的参数，这是 c++ 的约定，用以区分“前置++”）
	CppOperatorComplex operator++(int);

	// 通过友元函数重载 ostream 的 <<
	friend ostream& operator<<(ostream &, CppOperatorComplex &);

	// 类型转换函数，用以支持将 CppOperatorComplex 转换（隐式或显式）为 int
	operator int(); 
};

CppOperatorComplex CppOperatorComplex::operator+(CppOperatorComplex &coc) 
{
	CppOperatorComplex result;
	result.Name = this->Name + "+" + coc.Name;
	return result;
}

CppOperatorComplex operator*(CppOperatorComplex &coc1, CppOperatorComplex &coc2) 
{
	CppOperatorComplex result;
	result.Name = coc1.Name + "*" + coc2.Name;
	return result;
}

bool operator==(string &name, CppOperatorComplex &coc) 
{
	CppOperatorComplex result;
	return name == coc.Name;
}

CppOperatorComplex CppOperatorComplex::operator++() // 前置++
{
	this->Name = "++" + this->Name;
	return *this;// 返回自加后的当前对象
}
CppOperatorComplex CppOperatorComplex::operator++(int) // // 后置++
{
	CppOperatorComplex temp(*this);
	this->Name += "++";
	return temp;  // 返回的是自加前的对象
}

ostream& operator<<(ostream &output, CppOperatorComplex &coc)
{
	output << "name: " << coc.Name;
	return output;
}

CppOperatorComplex::operator int() //定义重载运算符的函数
{
	if (this->Name == "webabcd")
		return 100;
	return 10;
}



// 通过成员函数重载“+”运算符
void cppoperator_demo1()
{
	CppOperatorComplex coc1("webabcd");
	CppOperatorComplex coc2("wanglei");

	CppOperatorComplex coc = coc1 + coc2;
	string result = coc.ToString(); // webabcd+wanglei
}



// 通过友元函数重载“*”运算符
void cppoperator_demo2()
{
	CppOperatorComplex coc1("webabcd");
	CppOperatorComplex coc2("wanglei");

	CppOperatorComplex coc = coc1 * coc2;
	string result = coc.ToString(); // webabcd*wanglei
}



// 通过友元函数重载“==”运算符
void cppoperator_demo3()
{
	string name = "wanglei";
	CppOperatorComplex coc2("wanglei");

	bool result = (name == coc2); // true
}



// 通过成员函数重载“前置++”运算符
void cppoperator_demo4()
{
	CppOperatorComplex coc("wanglei");

	string s1 = (++coc).ToString(); // ++wanglei
	string s2 = coc.ToString(); // ++wanglei
}



// 通过成员函数重载“后置++”运算符
void cppoperator_demo5()
{
	CppOperatorComplex coc("wanglei");

	string s1 = (coc++).ToString(); // wanglei
	string s2 = coc.ToString(); // wanglei++
}



// 通过友元函数重载 ostream 的 <<
void cppoperator_demo6()
{
	CppOperatorComplex coc("wanglei");

	cout << coc << endl; // name: wanglei
}



// 类型转换函数的演示，隐式转换和显式转换
void cppoperator_demo7()
{
	CppOperatorComplex coc1("webabcd");
	CppOperatorComplex coc2("wanglei");

	// 由于结果是 int 类型，所以 coc1 和 coc2 会被隐式地转换为 int（通过“operator int()”来实现）
	int result = coc1 - coc2; // 90

	// 显式转换（通过“operator int()”来实现）
	result = int(coc1) - int(coc2); // 90
}



class CppOperatorA
{
private:
	string Name;
	int Age;
public:
	CppOperatorA(string name) : Name(name), Age(0)
	{

	}
	CppOperatorA(int age) : Age(age), Name("")
	{

	}
	string ToString()
	{
		return Name + int2string(Age);
	}
};

class CppOperatorB
{
private:
	string Name;
	int Age;
public:
	explicit CppOperatorB(string name) : Name(name), Age(0)
	{

	}
	explicit CppOperatorB(int age) : Age(age), Name("")
	{

	}
	string ToString()
	{
		return Name + int2string(Age);
	}
};

// 演示如何通过构造函数实现隐式转换
void cppoperator_demo8()
{
	CppOperatorA a1 = "webabcd"; // 编译器会调用 CppOperatorA(string name); 构造函数
	CppOperatorA a2 = 100; // 编译器会调用 CppOperatorA(int age); 构造函数

	string result1 = a1.ToString(); // webabcd0
	string result2 = a2.ToString(); // 100


	// CppOperatorB b1 = "webabcd"; // 由于构造函数 CppOperatorB(string name); 被修饰为 explicit，所以不能隐式调用此构造函数
	// CppOperatorB b2 = 100; // 由于构造函数 CppOperatorB(int age); 被修饰为 explicit，所以不能隐式调用此构造函数
}