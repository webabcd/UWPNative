/*
 * 友元（friend）函数, 友元类
 *
 * 友元函数: C++ 增加了一种称之为“友元(friend)”函数的声明，其用于将“特权”在本类中赋给一些函数(可以是全局函数，也可以是其它类的成员函数)，使之能够访问本类的私有和保护成员
 * 友元类: 如果 B 类是 A 类的友元类，则 B 中的所有函数都是 A 的友元函数，即 B 可以访问 A 的所有私有和保护成员
 */

#include "pch.h" 
#include "CppClass4.h" 
#include "cppHelper.h"

using namespace NativeDll;

void cppclass4_demo1();
void cppclass4_demo2();
void cppclass4_demo3();

string CppClass4::Demo()
{
	// 全局函数作友元函数
	cppclass4_demo1();

	// 其它类的成员函数作友元函数
	cppclass4_demo2();

	// 友元类
	cppclass4_demo3();


	return "看代码及注释吧";
}



class CppClass4Demo1Time
{
public:
	CppClass4Demo1Time(int h, int m, int s)
	{
		_hour = h;
		_minute = m;
		_second = s;
	}

	// 友元函数声明：声明全局函数 string ShowTime(CppClass4Demo1Time &); 是我的友元函数
	friend string ShowTime(CppClass4Demo1Time &); // 前面加 friend

private:
	int _hour;
	int _minute;
	int _second;
};

// 之前声明过的，我是 CppClass4Demo1Time 类的友元函数，我可以使用 CppClass4Demo1Time 对象中的 private 和 protected 属性和函数
string ShowTime(CppClass4Demo1Time &t)
{
	t._hour = 10;
	return int2string(t._hour) + ":" + int2string(t._minute) + ":" + int2string(t._second);
}

// 全局函数作友元函数的演示
void cppclass4_demo1()
{
	CppClass4Demo1Time t(8, 30, 15);
	string result = ShowTime(t); // 10:30:15
}



class CppClass4Demo2Date;  // 对 CppClass4Demo2Date 类的提前引用声明
class CppClass4Demo2Time 
{
public:
	CppClass4Demo2Time(int h, int m, int s) 
	{
		_hour = h;
		_minute = m;
		_second = s;
	}

	// 我这里用到了 CppClass4Demo2Date 类，但是其是在后面定义的，所以在此之前要通过“class CppClass4Demo2Date;”做提前引用声明
	string ShowTime(CppClass4Demo2Date &d);

private:
	int _hour;
	int _minute;
	int _second;
};

class CppClass4Demo2Date 
{
public:
	CppClass4Demo2Date(int y, int m, int d)  
	{
		_year = y;
		_month = m;
		_day = d;
	}

	// 友元函数声明：声明 CppClass4Demo2Time 类中的 string ShowTime(CppClass4Demo2Date &); 是我的友元函数
	friend string CppClass4Demo2Time::ShowTime(CppClass4Demo2Date &);

private:
	int _year;
	int _month;
	int _day;
	
};

// 之前声明过的，我是 CppClass4Demo2Date 类的友元函数，我可以使用 CppClass4Demo2Date 对象中的 private 和 protected 属性和函数
string CppClass4Demo2Time::ShowTime(CppClass4Demo2Date &d) 
{
	d._year = 2016;
	return int2string(d._year) + "-" + int2string(d._month) + "-" + int2string(d._day) + " " + int2string(_hour) + ":" + int2string(_minute) + ":" + int2string(_second);
}

// 其它类的成员函数作友元函数的演示
void cppclass4_demo2()
{
	CppClass4Demo2Time t(8, 30, 15);  
	CppClass4Demo2Date d(2015, 4, 3); 
	string result = t.ShowTime(d); // 2016-4-3 8:30:15
}



class CppClass4Demo3Date;
class CppClass4Demo3Time
{
public:
	CppClass4Demo3Time(int h, int m, int s)
	{
		_hour = h;
		_minute = m;
		_second = s;
	}

	string ShowTime(CppClass4Demo3Date &d);

private:
	int _hour;
	int _minute;
	int _second;
};

class CppClass4Demo3Date
{
	// 友元类声明：声明 CppClass4Demo3Time 类是我的友元类（CppClass4Demo3Time 类中的成员函数可以访问我的 private 和 protected 属性和函数）
	friend CppClass4Demo3Time;

public:
	CppClass4Demo3Date(int y, int m, int d)
	{
		_year = y;
		_month = m;
		_day = d;
	}

private:
	int _year;
	int _month;
	int _day;
};

// CppClass4Demo3Time 是 CppClass4Demo3Date 的友元类
// CppClass4Demo3Time 类中的成员函数可以访问 CppClass4Demo3Date 的 private 和 protected 属性和函数
string CppClass4Demo3Time::ShowTime(CppClass4Demo3Date &d)
{
	d._year = 2016;
	return int2string(d._year) + "-" + int2string(d._month) + "-" + int2string(d._day) + " " + int2string(_hour) + ":" + int2string(_minute) + ":" + int2string(_second);
}

// 友元类的演示
void cppclass4_demo3()
{
	// 注：
	// 1、如果 B 是 A 的友元类，那么 A 不一定是 B 的友元类
	// 2、如果 B 是 A 的友元类，C 是 B 的友元类，那么 C 不一定是 A 的友元类

	CppClass4Demo3Time t(8, 30, 15);
	CppClass4Demo3Date d(2015, 4, 3);
	string result = t.ShowTime(d); // 2016-4-3 8:30:15
}