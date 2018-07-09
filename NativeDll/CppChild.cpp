/*
 * 派生类（基类是 CppHuman）
 */

#include "pch.h" 
#include "CppChild.h" 
#include "cppHelper.h"

using namespace NativeDll;

string CppChild::Show()
{
	return "child: " + Name;
}

CppChild::CppChild(string name) : CppHuman(name)
{

}

CppChild::~CppChild()
{

}