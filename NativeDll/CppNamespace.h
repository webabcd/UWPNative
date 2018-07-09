#pragma once 

#include <string>

using namespace std;

// 定义一个命名空间，并在其中定义一个类以及声明一个函数
namespace NativeDll
{
	class CppNamespace
	{
	public:
		string Demo();

	public:
		string Demo2();
	};

	string demo3();

	string demo4();
}