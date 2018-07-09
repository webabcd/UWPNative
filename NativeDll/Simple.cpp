/*
 * .cpp 实现文件
 *
 * 为了支持 Windows Runtime Component 这种方式，所以引入 Microsoft created the Visual C++ component extensions (C++/CX)，可以将其看作是连接“调用者”和“C/C++”之间的桥梁，元数据是 windows metadata (.winmd) files
 * 为了让“调用者”调用 Windows Runtime Component，所以 C++/CX 会有自己的一些数据类型，比如字符串是 Platform::String^ 类型的，这样才能让“调用者”调用
 * 关于 C++/CX 的相关知识请参见：https://msdn.microsoft.com/en-us/library/hh755822.aspx
 */

#include "pch.h" // 预编译头文件
#include "Simple.h" // 需要实现的头文件

// 头文件中定义的命名空间
using namespace NativeDll;

// 实现头文件中的方法
int Simple::Add(int x, int y)
{
	return x + y;
}