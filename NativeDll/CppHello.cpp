/*
 * hello c++
 */

#include "pch.h" 
#include "CppHello.h" 

// 头文件中定义的命名空间
using namespace NativeDll;

// 实现头文件中的函数（之前要 using namespace NativeDll;）
string CppHello::Hello(string name)
{
	return "hello: " + name;
}

/*
什么是编译？

1、为了使计算机能执行高级语言源程序，需要用编译器(complier)把源程序翻译成二进制形式的目标程序(object program)
2、编译是以源程序文件为单位分别编译的，目标程序一般以.obj或.o作为后缀(object 的缩写)
3、得到多个目标文件后，需要用连接程序(linker)将一个程序的所有目标程序和系统的库文件以及系统提供的其他信息连接起来，最终形成一个可执行的二进制文件
*/