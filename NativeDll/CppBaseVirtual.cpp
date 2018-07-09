/*
 * 用于演示虚基类
 *
 * 注：
 * 1、虚基类并不是在声明基类时声明的，而是在声明派生类时，指定继承方式时声明的
 * 2、一个基类可以在生成一个派生类时作为虚基类，也可以在生成一个派生类时不作为虚基类
 */

#include "pch.h" 
#include "CppBaseVirtual.h" 

using namespace NativeDll;

CppBaseVirtual::CppBaseVirtual(int number) :Number(number)
{

}