/*
 * .h 头文件
 */

// 保证头文件只被编译一次（即使被多次引用，也只被编译一次）
#pragma once

#include <string> // 引入 cpp 语言头文件
#include <windows.h> // 引入 c 语言头文件

// 引入自定义 c 语言头文件
#include "cHello.h";
#include "cDataType.h";  
#include "cOperator.h";  
#include "cStatement.h";
#include "cPreprocessor.h";
#include "cIO.h"
#include "cArray.h";
#include "cFunction.h";
#include "cPointer.h";
#include "cStruct.h";
#include "cMemory.h";
#include "cFile.h";


// 使用 Platform 命名空间下的 String 类
using Platform::String;

// 使用 Platform 命名空间下的全部类
// using namespace Platform;

namespace NativeDll
{
	public ref class DemoC sealed
	{
	public:
		String^ HelloDemo();

	public:
		String^ DataTypeDemo();

	public:
		String^ OperatorDemo();

	public:
		String^ StatementDemo();

	public:
		String^ PreprocessorDemo();
	
	public:
		String^ IODemo();

	public:
		String^ ArrayDemo();

	public:
		String^ FunctionDemo();

	public:
		String^ PointerDemo();

	public:
		String^ StructDemo();

	public:
		String^ MemoryDemo();

	public:
		String^ FileDemo(String^ rootPath);


	private:
		String^ Char2String(char *input);
	};
}