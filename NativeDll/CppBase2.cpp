/*
 * 基类 2
 */

#include "pch.h" 
#include "CppBase2.h" 

using namespace NativeDll;

CppBase2::CppBase2(int number, string name, int age) :CppBaseVirtual(number), Name("cppbase2 " + name), Age(age)
{

}