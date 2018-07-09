/*
 * .cpp 实现文件
 *
 * 为了支持 Windows Runtime Component 这种方式，所以引入 Microsoft created the Visual C++ component extensions (C++/CX)，可以将其看作是连接“调用者”和“C/C++”之间的桥梁，元数据是 windows metadata (.winmd) files
 * 为了让“调用者”调用 Windows Runtime Component，所以 C++/CX 会有自己的一些数据类型，比如字符串是 Platform::String^ 类型的，这样才能让“调用者”调用
 * 关于 C++/CX 的相关知识请参见：https://msdn.microsoft.com/en-us/library/hh755822.aspx
 */

#include "pch.h" // 预编译头文件
#include "DemoCpp.h" // 需要实现的头文件
#include "cppHelper.h"

// 头文件中定义的命名空间
using namespace NativeDll;


String^ DemoCpp::HelloDemo(String^ name)
{
	string cppName = CXString2Cppstring(name);

	CppHello cppHello;
	string cppResult = cppHello.Hello(cppName);
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::DiffDemo()
{
	CppDiff cppDiff;
	string cppResult = cppDiff.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::ReferenceDemo()
{
	CppReference cppReference;
	string cppResult = cppReference.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::IO1Demo()
{
	CppIO1 cppIO1;
	string cppResult = cppIO1.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::IO2Demo(String^ rootPath)
{
	string cppRootPath = CXString2Cppstring(rootPath);

	CppIO2 cppIO2;
	string cppResult = cppIO2.Demo(cppRootPath);;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::IO3Demo()
{
	CppIO3 cppIO3;
	string cppResult = cppIO3.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::NamespaceDemo()
{
	CppNamespace cppNamespace;
	string cppResult = cppNamespace.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Function1Demo()
{
	CppFunction1 cppFunction1;
	string cppResult = cppFunction1.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Function2Demo()
{
	CppFunction2 cppFunction2;
	string cppResult = cppFunction2.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Class1Demo()
{
	CppClass1 cppClass1;
	string cppResult = cppClass1.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}


String^ DemoCpp::Class2Demo()
{
	CppClass2 cppClass2;
	string cppResult = cppClass2.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Class3Demo()
{
	CppClass3 cppClass3;
	string cppResult = cppClass3.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Class4Demo()
{
	CppClass4 cppClass4;
	string cppResult = cppClass4.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Class5Demo()
{
	CppClass5 cppClass5;
	string cppResult = cppClass5.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Class6Demo()
{
	CppClass6 cppClass6;
	string cppResult = cppClass6.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::Class7Demo()
{
	CppClass7 cppClass7;
	string cppResult = cppClass7.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}

String^ DemoCpp::OperatorDemo()
{
	CppOperator cppOperator;
	string cppResult = cppOperator.Demo();;
	String^ cxResult = cppstring2CXString(cppResult);

	return cxResult;
}



String^ DemoCpp::cppstring2CXString(string s)
{
	return ref new Platform::String(s2ws_3(s).c_str());
}

string DemoCpp::CXString2Cppstring(String^ s)
{
	return ws2s_3(std::wstring(s->Data()));
}