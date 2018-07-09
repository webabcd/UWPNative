/*
 * 字符串内存流
 */

#include "pch.h" 
#include "CppIO3.h" 

#include <iostream> 
#include <strstream> // istrstream(继承自istream), ostrstream(继承自ostream)

using namespace NativeDll;

void cppio3_demo1();
void cppio3_demo2();

string CppIO3::Demo()
{
	// 输入字符串流
	cppio3_demo1();

	// 输出字符串流
	cppio3_demo2();
	
	// 输入输出字符串流
	char a[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	strstream strio(a, sizeof(a), ios::in | ios::out);


	return "看代码及注释吧";
}


void cppio3_demo1()
{
	char a[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	char b[5];

	// 创建一个输入字符串流，其数据来源为 a，缓冲区大小为 sizeof(a)
	istrstream strin(a, sizeof(a));
	for (int i = 0; i < 5; i++)
	{
		// 将输入字符串流中的数据（即数据源 a ）赋值给 b
		strin >> b[i];
	}
	// 此时 b 中的数据为 abcde

}


void cppio3_demo2()
{
	char a[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	char c[6];

	// 创建一个输出字符串流，其数据输出的目标为 c，缓冲区大小为 sizeof(c)
	ostrstream strout(c, sizeof(c));
	for (int i = 0; i < 5; i++)
	{
		// 将数据 a 赋值给输出字符串流（即数据输出目标 c）
		strout << a[i];
	}
	// ends 就是 '\0'
	strout << ends;
	cout << c << endl; // 输出结果为 abcde
}