/*
 * 内联函数，函数模板
 */

#include "pch.h" 
#include "CppFunction2.h" 

using namespace NativeDll;

void function2_demo1();
void function2_demo2();

string CppFunction2::Demo()
{
	// 内联（inline）函数
	function2_demo1();

	// 函数模板（function template）
	function2_demo2();

	return "看代码及注释吧";
}



// 声明一个 inline 函数（左侧加 inline）
inline int function2_max(int i, int j);

// 内联（inline）函数的使用
void function2_demo1()
{
	int a = 1, b = 2;
	int x;

	// 内联函数（内置函数，内嵌函数，inline） - 在编译时将所调用函数的代码直接嵌入到主调函数中
	x = function2_max(a, b); // 2

	/*
	inline 函数会在编译时直接替换（类似宏替换），上面调用了 inline 函数，在编译时会被替换为如下代码
	if (a > b)
		x = a;
	x = b;
	*/
}

// 定义一个 inline 函数（左侧加 inline）
// 注意：从 inline 的原理看，其是以代码膨胀（复制）为代价，省去了函数调用的开销，从而提高函数的执行效率
// 1、当函数包含复杂的控制语句，如循环语句或 switch 语句或递归之类的时，不宜用 inline 函数
// 2、一般只将规模很小（5 句以下）且使用频繁的函数声明为 inline
// 3、总之，如果不值当的（执行效率提高小，代码膨胀大），建议不用 inline
inline int function2_max(int i, int j) 
{
	if (i > j)
		return i;
	return j;
}



// 声明一个函数模板，其有两个不定类型，分别为 T1 和 T2（typename 和 class 没有区别）
template<typename T1, class T2>

// 使用上面的函数模板中定义的类型，定义一个函数
T1 function2_template(T1 a, T2 b, int c) // 使用了函数模板的函数就是模板函数
{
	if (a > b)
		return a;
	return a + 100;
}

/*
这种写法是错误的，因为推导不出返回值的类型
T2 function2_template(T1 a, T1 b)
{
	if (a > b)
		return 100
	return 1000;
}
*/

void function2_demo2()
{
	float result;
	float i = 1.1f;
	int j = 2;

	// 调用指定的函数，此函数有不定类型的参数
	result = function2_template(i, j, 0); // 101.1
}