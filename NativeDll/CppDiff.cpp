/*
 * C++ 与 C语言的区别小介
 */

#include "pch.h" 
#include "CppDiff.h" 

using namespace NativeDll;

struct birth
{
	int year;
	int month;
	int day;
};

string CppDiff::Demo()
{
	/*
	我是多行注释
	ANSI C 只支持多行注释，而不支持单行注释
	*/


	// 我是单行注释 \
	    如果单行注释后面以“\”结尾则下一行也是注释 \
	    多行注释“/**/”是不能嵌套的，但是多行注释内可以有单行注释


	/*
	void fun(); // C 语言的这句代表可以传递任意参数，C++ 的这句代表不可以传递任何参数
	void fun(void); // C 语言的这句代表不可以传递任何参数，所以 C 语言建议无参数时要使用 void
	*/


	// C++ 可以取寄存器变量的地址，但编译器会将其变为内存变量（因为寄存器变量无地址）


	/*
	C 语言会把字符当做 int 类型
	C++ 会把字符当做 char 类型

	比如：sizeof('a')
	ANSI C99 会将其看作为 int 类型（32 位机器上一般编译器会让 int 占用 4 字节），所以会返回 4
	ISO C++ 会将其看作为 char 类型，占 1 字节，所以返回 1
	*/


	// C++ 的基本数据类型中新增了 bool 类型
	bool b = true;


	// 定义结构体变量时，C 语言要求是“struct 结构体名 变量名”，而在 C++ 中 struct 可以省略掉
	struct birth myBirth1;
	birth myBirth2;


	// 由逗号运算符连接的逗号表达式，一个表达式一个表达式地依次求解，整个表达式的值是最后一个表达式的值（注意，逗号运算符级别最低，要用括号括起来）
	int x = (x = 1, x += 1, ++x); // 3
	int y = (y = 1, y += 1, y++); // 2


	// std::string 可以非常简单地完成字符串的复制，拼接之类的功能
	std::string str1 = "webabcd";
	std::string str2 = "wanglei";
	std::string str3 = str1; // 复制字符串，相当于 strcpy
	str1 = "lalala"; // 改变 str1 不会影响 str3
	std::string str4 = str1 + " " + str2 + " " + str3; // 字符串拼接很简单


	return "看代码及注释吧";
}
