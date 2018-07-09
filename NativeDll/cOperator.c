/*
 * 运算符
 */

#include "pch.h"
#include "cOperator.h"
#include "cHelper.h"

char *demo_cOperator()
{
	// 算数运算符：+, -, *, /, %, ++, --
	// 关系运算符：>, <, ==, >=, <=, !=
	// 逻辑运算符：&&, ||, !
	// 位操作运算符：&, |, ~, ^, <<, >>
	//     & - 按位与：都是 1 则为 1，其他情况为 0；比如 1001 & 0001 = 0001
	//     | - 按位或：有一个是 1 则为 1，其他情况为 0；比如 1001 | 0001 = 1001
	//     ^ - 按位异或：不一样则为 1，一样则为 0；比如 1001 | 0001 = 1000
	//     ~ - 按位非：~1001 = 0110
	// 赋值运算符：=, +=, -=, *=, /=, %=, &=, |=, ^=, >>=, <<=
	// 条件运算符：三目运算符 ?:
	// 指针运算符：* 用于取内容   & 用于取地址
	


	// i++, i本身加1，表达式i++的值为i加1前的值
	// ++i, i本身加1，表达式++i的值为i加1后的值
	int i = 0;
	i++; // 此处 i 的值为 1, i++ 的值为 0
	int j = 0;
	++j; // 此处 j 的值为 1, ++j 的值为 1



	// sizeof - 是 C 里面的关键字，而不是函数，其是求字节数运算符

	// 计算一个数据类型所占用空间的大小
	int intSize = sizeof(short); // 2, 不同平台下 int short long 之类的占用空间可能不一样，用 sizeof 就可以知道其占用空间的大小了

	char *str = "abcdefghijklmnopqrstuvwxyz";
	int dataSize = sizeof(str); // 4, 这里计算的是 str 指针所占用空间的大小

	return str_concat2(int_toString(intSize), int_toString(dataSize));
}
