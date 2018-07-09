/*
 * 演示 C#, C++/CX, C/C++ 间的通信
 *
 * 本例是 C/C++ 部分
 */

#include "pch.h" 
#include "CppCx.h" 
#include "DemoCx.h"

using namespace NativeDll;

string CppCx::Hello(string name)
{
	// C/C++ 通过 C++/CX 调用 C#
	if (DemoCx::GlobalCallback != nullptr)
		DemoCx::GlobalCallback->Cx2Cs("c/c++ to c++/cx to cs");

	return "hello: " + name;
}
