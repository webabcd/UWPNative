/*
 * 函数重载，缺省参数
 */

#include "pch.h" 
#include "CppFunction1.h" 
#include "cppHelper.h" 

using namespace NativeDll;

string CppFunction1::Demo()
{
	// 函数重载（overload） - 根据参数类型和个数做函数重载（不能仅按返回值类型来做函数重载）
	string function1_get();
	string function1_get(string s1);
	string function1_get(int i1);
	string result1 = function1_get(); // function1_get
	string result2 = function1_get("abc"); // function1_get abc
	string result3 = function1_get(100); // function1_get 100


	// 缺省参数 - 函数参数允许有缺省值，为某个参数提供缺省值后，则必须为其后面的参数提供缺省值
	int function1_sum(int x, int y = 1, int z = 2);
	int a = function1_sum(100); // 103
	int b = function1_sum(100, 100); // 202
	int c = function1_sum(100, 100, 100); // 300


	return "看代码及注释吧";
}


// 如果函数参数有缺省值，且有函数声明的话，则缺省值应该在函数声明处指定（此时在函数定义处指定函数缺省值是无效的）
int function1_sum(int x, int y, int z) 
{ 
	return x + y + z; 
}


// 以下几个函数用于演示函数重载
string function1_get()
{
	return "function1_get";
}
/*
不能仅按返回值类型来做函数重载（有这句的话会编译错误）
int function1_get()
{
	return 100;
}
*/
string function1_get(string s1)
{
	return "function1_get " + s1;
}
string function1_get(int i1)
{
	return "function1_get " + int2string(i1);
}
