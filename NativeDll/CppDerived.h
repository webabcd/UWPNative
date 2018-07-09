#pragma once 

#include <string>
#include "CppBase1.h"
#include "CppBase2.h"

using namespace std;

namespace NativeDll
{
	class CppDerived : public CppBase1, public CppBase2
	{

	public:
		CppDerived(int number, string name, float salary, int age);

		string Show();

	};
}
