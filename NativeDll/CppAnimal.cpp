/*
 * 用于基类的演示
 */

#include "pch.h" 
#include "CppAnimal.h" 
#include "cppHelper.h"

using namespace NativeDll;

string CppAnimal::Show()
{
	return "animal: " + int2string(Number) + " " + Name;
}

CppAnimal::CppAnimal(int number) :Number(number)
{
	Name = "动物";
}