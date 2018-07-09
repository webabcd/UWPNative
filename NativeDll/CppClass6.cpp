/*
 * 多重继承（multiple inheritance）, 虚基类（virtual base class）
 */

#include "pch.h" 
#include "CppClass6.h" 
#include "CppDerived.h" 

using namespace NativeDll;

string CppClass6::Demo()
{
	CppDerived derived(0, "webabcd", 100.0f, 35);
	string result = derived.Show(); // cppbase1 webabcd 100.00 35

	return result;
}
