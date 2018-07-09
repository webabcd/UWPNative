/*
 * 函数
 *
 *
 * 1、从变量的作用域（scope）角度来分，可以分为全局变量（外部变量）和局部变量
 * 2、从变量的生存期角度来分，可以分为静态存储方式和动态存储方式
 *
 *
 * argument - 实参
 * parameter - 形参
 */

#include "pch.h"
#include "cFunction.h"
#include "cHelper.h"


// 全局变量（亦称外部变量），作用域（scope）是整个源程序
int global01 = 100;


// 像这种定义在 .c 中的函数（无论在 .c 文件中有无函数声明），如果想被外部文件调用的话，则外部文件在调用之前需要先声明
void function0()
{
	;
}

char *demo_cFunction()
{
	// 函数定义在之前，则不用声明也可以调用（同一文件）；函数定义在之后，则必须先声明才可以调用
	function0();



	// 以下为无参数无返回值的函数声明（declare），其同 void demo_cFunction1();
	void function1(void);

	// 以下为有参数有返回值的函数声明
	int function2(int a, int b);
	
	// 也可以将上面的函数声明写成下面这种形式，像这种只有参数类型，没有参数名称的函数声明称之为函数原型（function prototype）
	// int demo_cFunction2(int, int); 


	// 无参数，无返回值函数演示
	function1();


	// 有参数，有返回值函数演示
	int a = 1, b = 1;  // 这里的 a 和 b 是实参
	int x = function2(a, b);


	// 函数递归
	long y = recursion(100); // 结果：5050


	// 向函数传递数组类型的演示
	// 之前说过 ary 是数组的首地址，也就是说传递过去的是指针，也就是说实参和形参其实指向的是一个地方，相当于引用类型
	int ary[] = {0, 1, 2, 3, 4 };
	update(ary, 5); // 数组 ary 被更新了


	// 局部变量和全局变量的演示
	demo_variable1();


	// 变量存储方式的演示
	demo_variable2();


	// 参数不定的函数（可变参数）
	demo_params();


	return "看代码及注释吧";
}


// 无参数，无返回值函数演示
void function1()
{
	// 空参数时，写 void 和不写 void 的区别（C 语言建议没有参数时使用 void）

	/*
	void fun(); // 代表可以传递任意参数（C++ 则代表不能传递任何参数）
	fun(1); // 正常编译（在本例中这么做其实是会编译错误的，因为用的是 C++ 编译器）
	fun(1, 2, 3); // 正常编译（在本例中这么做其实是会编译错误的，因为用的是 C++ 编译器）
	*/

	/*
	void fun(void); // 代表不能传递任何参数
	fun(1); // 编译错误
	fun(1, 2, 3); // 编译错误
	*/
}


// 有参数，有返回值函数演示
int function2(int a, int b) 
{
	// 这里的 a 和 b 是形参，形参就是实参的副本
	// 形参变量只在被调用期间才分配内存单元，调用结束立即释放，也就是说形参变量只有在函数内才是有效的，离开该函数就不能再使用了，即形参的作用于在函数内
	return a + b;
}


// 演示函数的递归调用
// return: 0 + 1 + 2 + 3 + ... + n
long recursion(int n)
{
	long result = 0 ;
	
	if (n > 0)
	{
		result += n;
		result += recursion(n - 1);
	}

	return result;
}


// 参数为数组类型的演示（之所以需要传递 aryLength 数组长度，是因为传递过来的 ary 是个指针，无法计算其指向的数组长度。就好像 main 函数似的，需要传递参数个数）
void update(int ary[], int aryLength)
{
	// 此处实参和形参其实指向的是一个地方
	for (int i = 0; i < aryLength; i++)
	{
		ary[i] = 0;
	}

}


// 局部变量和全局变量的演示
void demo_variable1()
{
	// 我是局部变量，作用域在函数内
	int i = 1;
	{
		// 我是复合语句内的局部变量，作用域在复合语句内，会屏蔽外面的同名变量
		int i = 2;
	}

	// 我是局部变量，如果全局变量有与我同名的，则“屏蔽”全局变量
	int global01 = 200;

	// 上面“屏蔽”了全局变量，那我要怎么引用全局变量呢？像下面这样用“::”
	int global01Outside = ::global01; // c++
}


// 变量存储方式的演示
void demo_variable2()
{
	// 从变量的生存期角度来分，可以分为静态存储方式和动态存储方式
	// 1、静态存储方式：是指在程序运行期间分配固定的存储空间的方式
	// 2、动态存储方式：是在程序运行期间根据需要进行动态的分配存储空间的方式


	// 全局变量在程序运行期间都会被分配固定的存储空间（静态存储方式）

	// 局部变量默认就是 auto 的，即动态分配存储空间。下面这句写全了就是 auto int i = 0;（动态存储方式）
	int i = 0;  

	// 如果希望函数中的局部变量的值在函数调用结束后不消失的话，则应该用 static 指定局部变量为“静态局部变量”（静态存储方式）
	static int j = 0;

	// 用 register 指定“寄存器变量”，其会保存在 cpu 中的寄存器中。一个最佳场景是，将其作为循环控制的变量
	// 寄存器变量无地址，所以不能用“&”对其取地址（C++ 可以取其地址，但是编译器会自动将其变为内存变量）。另外，寄存器不够用的话会自动变为内存变量
	register int x = 0;
	
	// 用 volatile 保证变量必在内存中，而不会被放入 cpu 寄存器（如果编译器认为某变量无外部修改，则为了优化会将其放入寄存器）
	volatile int y = 0;


	// 全局变量是在函数的外部定义的，它的作用域为从变量定义处开始，到本程序文件的末尾
	// 如果在定义点之前的函数想引用该全局变量，则应该使用 extern 表明该变量在别的地方已经定义过了，在这里要使用那个变量
	extern int global02, global03; // 如果没有这句的话，则编译会报“未声明的标识符”的错误

	int p02 = global02;
	int p03 = global03;
}

int global02 = 200, global03 = 300;



// 以下演示如何定义及使用参数不定的函数（可变参数）

#include <stdarg.h> // 其定义了 va_start, va_arg, va_end （va 应该是 variable argument（可变参数）的简写）

void demo_params()
{
	// 计算 n 个整数的平均值，第一个参数代表后面的参数的个数
	float average(int paramCount, ...);

	float result =  average(4, 1, 2, 3, 4); // 2.5
}

float average(int paramCount, ...)
{
	// 定义一个参数列表
	va_list va_params;

	long sum = 0;

	// 告知不定参数的个数，并准备读取参数
	va_start(va_params, paramCount);

	for (int i = 0; i < paramCount; i++)
	{
		// 一个一个地按照指定的类型读取参数的值，每读取完一个，参数指针就会向后移动继续读取下一个
		int value = va_arg(va_params, int);
		sum += value;
	}

	// 停止读取参数
	va_end(va_params);

	return sum * 1.0f / paramCount;
}