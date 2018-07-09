// 保证文件只被编译一次（即使被多次引用，也只被编译一次）
/*
 * #ifndef 的方式依赖于宏名字不能冲突
 * #pragma once 保证同一个文件不会被多次编译，这里的“同一个文件”是指物理上的一个文件
 * #pragma once 依赖于编译器；而 #ifndef 则受语言天生的支持
*/
#pragma once 


// 包含指定头文件
/*
 * 举个例子：
 * <string.h> 是 c 标准库下的文件
 * <cstring> 包含了 c 标准库下的 string.h 文件，并放置在命名空间 std 下
 * <string> 是 c++ 标准库的 string 类，在命名空间 std 下
 */
#include <string>


// 引用命名空间 std （std - standard）
using namespace std;


// 自定义命名空间
namespace NativeDll
{
	class CppHello 
	{
	public:
		string Hello(string name);
	};
}