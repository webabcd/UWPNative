/*
 * 命名空间
 */

#include "pch.h" 
#include "CppNamespace.h" 

using namespace NativeDll;

// 不指定命名空间则是全局的
void namespace_demo1();
void namespace_demo2();
void namespace_demo3();

// 实现 NativeDll 命名空间中的函数
string CppNamespace::Demo() // 写全了就是 string NativeDll::CppNamespace::Demo()
{
	// 命名空间的定义及使用
	namespace_demo1();

	// 命名空间的嵌套及使用
	namespace_demo2();

	// 没有名字的命名空间的定义及使用
	namespace_demo3();

	
	return Demo2() + demo3() + demo4();
}

// 实现 NativeDll 命名空间中的函数
string NativeDll::demo3() // 必须要指定命名空间，否则就是全局的
{
	return "demo3";
}

// 实现 NativeDll 命名空间中的函数
namespace NativeDll
{
	string CppNamespace::Demo2()
	{
		return "Demo2";
	}

	string demo4()
	{
		return "demo4";
	}
}



// 定义 2 个命名空间
namespace ns1
{
	string getString()
	{
		return "ns1";
	}
}
namespace ns2
{
	string getString()
	{
		return "ns2";
	}
}
namespace ns2 // 命名空间是可以多次定义的
{
	string getString2()
	{
		return "ns2 getString2";
	}
}

// 命名空间的使用
void namespace_demo1()
{
	string result = "";


	// 调用指定命名空间下的函数
	result = ns1::getString(); // ns1
	result = ns2::getString(); // ns2


	// 引入指定的命名空间
	using namespace ns2; // 之后 ns2 有效
	result = getString(); // ns2

	using namespace ns1; // 之后 ns1 和 ns2 同时有效
	// result = getString(); // 编译错误，因为不明确


	// 引入指定命名空间的指定函数
	using ns1::getString; // 之后如果使用 getString() 函数，则其是来自 ns1 下的
	result = getString(); // ns1

	// using ns2::getString; // 编译错误，和 using ns1::getString; 冲突了
}



// 定义 1 个嵌套的命名空间
namespace nsA
{
	string getString()
	{
		return "nsA";
	}

	namespace nsB
	{
		string getString()
		{
			return "nsB";
		}
	}
}

void namespace_demo2()
{
	string result = "";

	// 嵌套命名空间的使用
	result = nsA::nsB::getString(); // nsB

	// 可以为嵌套命名空间设置别名（非嵌套的命名空间也可以设置别名）
	namespace ns = nsA::nsB;
	result = ns::getString(); // nsB
}



// 在名为 nsX 的命名空间下定义一个没有名字的命名空间
namespace nsX
{
	// 匿名命名空间
	namespace
	{
		string getStringAnonymous()
		{
			return "getStringAnonymous";
		}
	}

	// 内部可以直接调用没有名字的命名空间下的函数
	string getString()
	{
		return "getString() " + getStringAnonymous();
	}
}

void namespace_demo3()
{
	string result = "";

	// 外部也可以直接调用指定命名空间下的匿名命名空间中的函数
	result = nsX::getStringAnonymous(); // getStringAnonymous
	result = nsX::getString(); // getString() getStringAnonymous
}