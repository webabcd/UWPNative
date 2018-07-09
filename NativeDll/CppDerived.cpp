/*
 * 派生类
 *
 *
 * 在多重继承的情况下：
 * 1、如果 A 是 B C D E 的基类，F 同时继承了 B C D E，那么实例化 F 时会保存 4 份 A 成员
 * 2、如果 A 是 B 的基类，A 是 C D E 的虚基类（虚基类会使得在继承间接共同基类时只保留一份成员），F 同时继承了 B C D E，那么实例化 F 时会保存 2 份 A 成员（从 C D E 的路径上保留一份，从 B 的路径上保留一份）
 *
 *
 * 本例中：
 * 1、CppBaseVirtual 是 CppBase1 和 CppBase2 的虚基类
 * 2、CppDerived 继承了 CppBase1 和 CppBase2（多重继承）
 * 3、此种情况，实例化 CppDerived 只会保留一份 CppBaseVirtual 成员（因为 CppBaseVirtual 是 CppBase1 和 CppBase2 的虚基类）
 * 4、C++ 编译器只会执行最后的派生类（CppDerived）对虚基类（CppBaseVirtual）的构造函数的调用，而忽略虚基类的直接派生类（CppBase1 和 CppBase2）对虚基类的构造函数的调用，这就保证了虚基类的数据成员不会被多次初始化
 */

#include "pch.h" 
#include "CppDerived.h" 
#include "cppHelper.h"

using namespace NativeDll;

// 在无虚基类的情况下，派生类的构造函数中只需负责对其直接基类初始化
// 如果有虚基类，且虚基类中定义了带参数的构造函数，且没有定义默认构造函数，那么派生类不仅要负责对其直接基类进行初始化，还要负责对虚基类初始化
CppDerived::CppDerived(int number, string name, float salary, int age) :CppBaseVirtual(number), CppBase1(number, name, salary), CppBase2(number, name, age)
{

}

string CppDerived::Show()
{
	// 关于多重继承的二义性（ambiguous），如果派生类同时继承的多个基类有相同的成员，则调用这些成员时需显式指定其基类
	return CppBase1::Name + " " + float2string(Salary) + " " + int2string(Age);

	// 另外：当然，如果派生类与多个基类有相同成员的话，那么基类中的这些与派生类相同的成员都会被隐藏掉（即派生类中的成员会覆盖基类中的成员）
}