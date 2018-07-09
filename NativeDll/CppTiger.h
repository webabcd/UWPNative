#pragma once 

#include <string>
#include "CppAnimal.h"
#include "CppEmployee.h"

using namespace std;

namespace NativeDll
{
	/*
	 * 基类（base class）
	 * 派生类（derived class）
	 * 继承（inheritance）
	 * 组合（composition） - 在一个类中以另一个类的对象作为数据成员的，称为类的组合
	 *
	 *
	 * public 继承：派生类不能访问基类的私有成员；基类的公有成员在派生类中依然是公有成员；基类的保护成员在派生类中依然是保护成员
	 * private 继承（默认值）：派生类不能访问基类的私有成员；基类的公有成员在派生类中变为私有成员；基类的保护成员在派生类中变为私有成员
	 * protected 继承：派生类不能访问基类的私有成员；基类的公有成员在派生类中变为保护成员；基类的保护成员在派生类中依然是保护成员
	 */

	class CppTiger : public CppAnimal // 我是 public 继承，这是最常用的
	// class CppTiger : private CppAnimal // 我是 private 继承
	// class CppTiger : protected CppAnimal // 我是 protected 继承
	// class CppTiger : CppAnimal // 默认是 private 继承
	{

	private:
		string NickName;

		// 在一个类中以另一个类的对象作为数据成员的，称为类的组合
		CppEmployee employee; // 我是 CppTiger 的子对象（subobject）

	protected:
		// 派生类中的属性，如果其属性名与基类中的一样（不考虑属性的类型），则隐藏基类中的相应的属性（即派生类中的属性覆盖了基类中的属性）
		float Age;

	public:
		// 构造函数不会从基类继承过来，需要在派生类中自己写（注：析构函数也不会从基类继承过来，需要在派生类中自己写）
		CppTiger(int number);
		CppTiger(int number, string name, string nickName);

		// 用于演示如何在构造函数中，用简单的方式实例化子对象
		CppTiger(int tigerNumber, string tigerName, int employeeNumber, string employeeName);

		// 派生类中的函数，如果其函数名和参数与基类中的一样（不考虑返回值类型），则隐藏基类中的相应的函数（即派生类中的函数覆盖了基类中的函数）
		string Show();
	};
}
