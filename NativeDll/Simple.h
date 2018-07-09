/*
 * .h 头文件
 */

// 保证文件只被编译一次（即使被多次引用，也只被编译一次）
#pragma once 

namespace NativeDll // 命名空间
{
	public ref class Simple sealed // 类
	{
	public:
		int Add(int x, int y); // 方法
	};
}