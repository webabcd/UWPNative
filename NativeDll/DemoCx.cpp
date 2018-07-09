/*
 * 演示 C#, C++/CX, C/C++ 间的通信
 *
 * 本例是 C++/CX 部分
 *
 * 为了支持 Windows Runtime Component 这种方式，所以引入 Microsoft created the Visual C++ component extensions (C++/CX)，可以将其看作是连接“调用者”和“C/C++”之间的桥梁，元数据是 windows metadata (.winmd) files
 * 为了让“调用者”调用 Windows Runtime Component，所以 C++/CX 会有自己的一些数据类型，比如字符串是 Platform::String^ 类型的，这样才能让“调用者”调用
 * 关于 C++/CX 的相关知识请参见：https://msdn.microsoft.com/en-us/library/hh755822.aspx
 */

#include "pch.h" 
#include "DemoCx.h" 
#include "CppCx.h" 
#include "cppHelper.h"

using namespace NativeDll;

String^ DemoCx::HelloCx(String^ name)
{
	// 如果 C# 端设置了 ICallback 对象，则可以在 C++/Cx 端向 C# 端发送数据
	if (GlobalCallback != nullptr)
		GlobalCallback->Cx2Cs("c++/cx to cs");

	return "hello: " + name;
}

// 由 C# 调用，用于设置 ICallback 对象
void DemoCx::SetCallback(ICallback^ callback)
{
	GlobalCallback = callback;
}


String^ DemoCx::HelloCpp(String^ name)
{
	// C++/CX 与 C/C++ 通信时，如果要传递字符串，则要对字符串做转换
	string cppName = ws2s_3(std::wstring(name->Data()));

	// C++/CX 调用 C/C++
	CppCx cppCx;
	string cppResult = cppCx.Hello(cppName);
	String^ cxResult = ref new Platform::String(s2ws_3(cppResult).c_str());

	return cxResult;
}