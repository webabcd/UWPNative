/*
 * 常量，变量，基本数据类型的相关知识点
 *
 * 
 * 定义变量的时候就会分配内存，比如：
 * int i; // 定义时就分配了内存
 * i = 100; // 为那块内存赋值
 *
 * 注：
 * 1、声明一个变量意味着向编译器描述变量的类型，并分配存储空间
 * 2、声明了一个变量后，如果需要使用的话则需要对其赋值，未赋值的变量不能使用
 */

#include "pch.h"
#include "cDataType.h"
#include "cHelper.h"

#define CONSTANT1 100
#define CONSTANT2 3.14 // 常量中定义浮点型就是 double 类型的
#define CONSTANT3 "常量"

char *demo_cDataType()
{
	char *str1 = demo_constant();
	char *str2 = demo_integer();
	char *str3 = demo_float();
	char *str4 = demo_char();

	// 关于基本数据类型之间的转换
	float a = 3.14;
	int b = a; // 自动转换
	int c = (int)a; // 强制转换
	int d = int(a); // 强制转换（c++）

	return str_concat4(str1, str2, str3, str4);
}


// 常量的知识点
char *demo_constant()
{
	char *str1 = int_toString(CONSTANT1);
	char *str2 = float_toString(CONSTANT2);
	char *str3 = CONSTANT3;

	// 这是 const 常量
	const int i = 0;

	// const 常量和 #define 常量的区别，如下：
	/*
		如果是 #define x 1 + 2
		那么表达式 3 * x * 4 就相当于 3 * 1 + 2 * 4，结果是 11
		如果是 const int x = 1 + 2
		那么表达式 3 * x * 4 就相当于 3 * 3 * 4，结果是 36

		由上可知每次引用 #define 时都会做一次内存分配；而 const 仅在定义的时候分配一次内存



		严格来说 const 就是一个不可变的变量，在 ANSI C 标准中，如下写法就是错误的（注：ANSI C99 是允许用变量定义局部数组大小的）
		const int n = 10;
		int ary[n];
		因为 ANSI C 标准规定了定义数组的长度时必须用常量，而 const 的本质是一个变量（虽然不可变）
	 */

	return str_concat3(str1, str2, str3);
}


// 整型的知识点
char *demo_integer()
{
	// 对于 32 位系统来说，其占用 4 字节（其区间为：-2147483648~2147483647）
	int i = 0;

	// 对于 32 位系统来说，其通常占用 2 字节（标准要求只要不大于 int 即可）
	short si = 0; 

	// 对于 32 位系统来说，其通常占用 8 字节（标准要求只要不小于 int 即可）
	long li = 0L; // L 或 l 代表长整形

	// 对于 32 位系统来说，其占用 4 字节
	unsigned ui = 0U; // U 或 u 代表无符号整型（其区间为：0~4294967295）

	// 对于 32 位系统来说，其通常占用 8 字节（标准要求只要不小于 int 即可）
	unsigned long ul = 0UL; // UL 或 ul 代表无符号长整形
	


	// 以“0”开头就是八进制，其十进制的结果为 13
	int x = 015; 

	// 以“0X”开头就是十六进制，其十进制的结果为 65535
	int y = 0XFFFF; 



	// 演示一下什么是数据的溢出？
	// 假定 short 占用 2 个字节，其最大值为 32767，那么再加 1 呢，就变成 -32768 了，原理如下：
	// 有符号 32767 的二进制为 0111111111111111，加 1 后变为 1000000000000000 ,就是 -32768 了
	short abc = 32767;
	abc++; // -32768



	// 注意：对于有符号数据来说，左面第 1 表示符号，0 表示正，1 表示负
	// 判断一个数字是否有符号
	if (ui >= 0 && ~ui >= 0) // ~ 是取反操作
		return "unsigned int 是无符号";
	else
		return "bug";
}


// 浮点型的知识点
char *demo_float()
{
	// 4 字节
	float f = 3.14F; // F 或 f 代表浮点型

	// 8 字节
	double f2 = 3.14F;

	// 16 字节
	long double f4 = 3.14F;



	// 指数形式，即科学表示法
	float x = 0.00314E3; // 等于 0.00314 * 10的3次方
	float y = 314E-2; // 等于 314 * 10的-2次方（负数幂就是其正数幂的倒数，即 10 的 -2 次方的值为：1/100）



	// 通过科学表示法来理解浮点型数据在内存中的存放形式
	// 在科学表示法中，S=M*2^N 主要由三部分构成：符号位+阶码(N)+尾数(M)
	// 对于float型数据，其二进制有32位，其中符号位1位，阶码8位，尾数23位；对于double型数据，其二进制为64位，符号位1位，阶码11位，尾数52位。

	return  float_toString(y);
}


// 字符型的知识点
char *demo_char()
{
	// 用单引号标记字符类型
	char c = 'x';



	// 常用转义字符
	// \r - 回车
	// \n - 换行
	// \t - 制表
	// \b - 退格
	// \\ - \
	// \' - 单引号
	// \" - 双引号



	// \ 后面跟一个 ASCII 的八进制值，则结果为其对应的字符
	char *str1 = "\101"; // A
	
	// \x 后面跟一个 ASCII 的十六进制值，则结果为其对应的字符
	char *str2 = "\x41"; // A

	// 字符在内存中的保存形式：保存的就是其对应的 ASCII 码值
	int ascii = (int)c; // 120, 即 \x78


	// 用双引号标记字符串类型，字符串其实就是字符数组
	// 字符串的结束标识为：'\0'，即 ASCII 码中的 0，也就是 NULL
	// 也就是说，字符串的占用空间为：字符串的字节数 + 1
	char str[] = "abc"; // 其在内存中的存放形式为：abc\0，占用 4 个字节

	return str_concat2(str1, str2);
}
