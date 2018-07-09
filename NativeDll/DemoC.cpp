/*
 * .cpp 实现文件
 *
 * 为了支持 Windows Runtime Component 这种方式，所以引入 Microsoft created the Visual C++ component extensions (C++/CX)，可以将其看作是连接“调用者”和“C/C++”之间的桥梁，元数据是 windows metadata (.winmd) files
 * 为了让“调用者”调用 Windows Runtime Component，所以 C++/CX 会有自己的一些数据类型，比如字符串是 Platform::String^ 类型的，这样才能让“调用者”调用
 * 关于 C++/CX 的相关知识请参见：https://msdn.microsoft.com/en-us/library/hh755822.aspx
 */

#include "pch.h"
#include "DemoC.h"

// 头文件中定义的命名空间
using namespace NativeDll;

String^ DemoC::HelloDemo()
{
	return Char2String(demo_cHello("webabcd"));
}

String^ DemoC::DataTypeDemo()
{
	return Char2String(demo_cDataType());
}

String^ DemoC::OperatorDemo()
{
	return Char2String(demo_cOperator());
}

String^ DemoC::StatementDemo()
{
	return Char2String(demo_cStatement());
}

String^ DemoC::PreprocessorDemo()
{
	return Char2String(demo_cPreprocessor());
}

String^ DemoC::IODemo()
{
	return Char2String(demo_cIO());
}

String^ DemoC::ArrayDemo()
{
	return Char2String(demo_cArray());
}

String^ DemoC::FunctionDemo()
{
	return Char2String(demo_cFunction());
}

String^ DemoC::PointerDemo()
{
	return Char2String(demo_cPointer());
}

String^ DemoC::StructDemo()
{
	return Char2String(demo_cStruct());
}

String^ DemoC::MemoryDemo()
{
	return Char2String(demo_cMemory());
}

String^ DemoC::FileDemo(String^ rootPath)
{
	/* ascii 版
	const wchar_t *w = rootPath->Data();
	int size = wcslen(w);
	char *s = new char[size + 1];
	s[size] = 0;
	for (int i = 0; i<size; i++)
	{
		s[i] = (char)w[i];
	}
	*/

	const wchar_t *w = rootPath->Data();
	int size = wcslen(w);
	char s[256];
	int len = WideCharToMultiByte(CP_OEMCP, 0, w, -1, s, 0, 0, 0);
	len == WideCharToMultiByte(CP_OEMCP, 0, w, -1, s, len, 0, 0);

	return Char2String(demo_cFile(s));
}



String^ DemoC::Char2String(char *input)
{
	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, input, strlen(input) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));

	String^ str = ref new String(wszClassName);
	return str;
}
