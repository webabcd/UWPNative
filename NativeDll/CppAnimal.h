#pragma once 

#include <string>

using namespace std;

namespace NativeDll
{
	class CppAnimal
	{
	private:
		int Number;

	protected: 
		string Name;
		int Age;

	public:
		string Show();

		CppAnimal(int number);
	};
}
