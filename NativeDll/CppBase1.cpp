/*
 * 基类 1
 */

#include "pch.h" 
#include "CppBase1.h" 

using namespace NativeDll;

CppBase1::CppBase1(int number, string name, float salary) :CppBaseVirtual(number), Name("cppbase1 " + name), Salary(salary)
{

}