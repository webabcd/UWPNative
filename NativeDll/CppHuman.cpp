/*
 * 基类
 */

#include "pch.h" 
#include "CppHuman.h" 
#include "cppHelper.h"

using namespace NativeDll;

string CppHuman::Show()
{
	return "human: " + Name;
}

CppHuman::CppHuman(string name) : Name(name)
{

}

CppHuman::~CppHuman()
{

}