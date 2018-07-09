/*
 * .h 头文件（C++/CX）
 */

#pragma once 

#include "CppHello.h";
#include "CppDiff.h";
#include "CppReference.h";
#include "CppIO1.h"
#include "CppIO2.h"
#include "CppIO3.h"
#include "CppNamespace.h";
#include "CppFunction1.h";
#include "CppFunction2.h";
#include "CppClass1.h";
#include "CppClass2.h"
#include "CppClass3.h"
#include "CppClass4.h"
#include "CppClass5.h"
#include "CppClass6.h"
#include "CppClass7.h"
#include "CppOperator.h"

using namespace Platform;

// 自定义命名空间
namespace NativeDll 
{
	// ref class 可被输出到元数据（winmd - Windows Metadata），以便其他托管程序调用
	public ref class DemoCpp sealed 
	{
		// 用“^”标记的，系统会负责他们的引用计数，当引用计数为 0 时，它们会被销毁
	public:
		String^ HelloDemo(String^ name);

	public:
		String^ DiffDemo();

	public:
		String^ ReferenceDemo();

	public:
		String^ IO1Demo();

	public:
		String^ IO2Demo(String^ rootPath);

	public:
		String^ IO3Demo();

	public:
		String^ NamespaceDemo();

	public:
		String^ Function1Demo();

	public:
		String^ Function2Demo();

	public:
		String^ Class1Demo();

	public:
		String^ Class2Demo();

	public:
		String^ Class3Demo();

	public:
		String^ Class4Demo();

	public:
		String^ Class5Demo();

	public:
		String^ Class6Demo();

	public:
		String^ Class7Demo();

	public:
		String^ OperatorDemo();



	private:
		String^ cppstring2CXString(string s);

	private:
		string CXString2Cppstring(String^ s);
	};
}