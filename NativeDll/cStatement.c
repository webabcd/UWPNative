/*
 * 表达式，条件语句，循环语句，控制语句，空语句等
 */

#include "pch.h"
#include "cStatement.h"
#include "cHelper.h"

char *demo_cStatement()
{
	// 所谓表达式是由运算及运算对象所组成的具有特定含义的式子
	// 所谓表达式语句就是由表达式加上分号“;”组成的
	// i++, i本身加1，表达式i++的值为i加1前的值
	// ++i, i本身加1，表达式++i的值为i加1后的值


	
	// 复合语句（拿大括号括起来）
	{
		int p1 = 1;
		int p2 = 2;
	}



	// 只有“;”的语句就叫做空语句
	while (0)
	{
		; // 这一句就是空语句
	}
	// 上面的等于下面的
	while (0)
		;
	// 上面的等于下面的
	while (0);



	// 分支结构的语句（if else）
	int a = 0, b;

	if (a == 1) b = 1; // 注意：变量 a 在此之前如果不初始化的话，则这里是无法编译过的，也就是说未赋值的变量不能使用

	if (a == 1)
		b = 2;
	else if (a == 2)
		b = 3;
	else
		b = 4;



	// 分支结构的语句（switch case）
	int x = 0, y;
	switch (x)
	{
		case 1:
			y = 2;
			break;
		case 2:
			y = 3;
			break;
		default:
			y = 4;
	}



	// 分支结构的语句（?:）
	int m, n = 0;
	m = n == 1 ? 2 : 3;



	// 循环语句（while）
	int i = 0;
	while (i < 100)
	{
		i++;
	}



	// 循环语句（do while）
	int j = 0;
	do
	{
		j++;
	} 
	while (j < 100);



	// 循环语句（for）
	for (i = 0; i < 100; i++)
	{
	}
	for (i = 0; i < 100; )
	{
		i++;
	}
	for (i = 0, j = 0; i < 100 && j < 100; i++, j++)
	{
		i++;
		j++;
	}
	int z = 0;
	for ( ; z < 100; )
	{
		z++;
	}

	

	// 转向语句：break - 跳出循环
	// 转向语句：continue - 跳过循环体的剩余的语句，直接进入下一次循环判断
	// 转向语句：return - 退出函数，并提供返回值
	// 转向语句：goto - 跳转至指定的标识符处，并执行其后的语句（需合理使用，比如多层嵌套语句退出时，使用 goto 就是很合理的）

	int result = 0;
myAnchor: // 自定义标识符（标识符加冒号）
	if (result == 1)
	{
		result = 100;
	}
	if (result == 0)
	{
		result = 1;
		goto myAnchor; // 跳转至指定的标识符处（myAnchor:），并执行其后的语句
	}


	return str_concat2("看代码及注释吧", int_toString(result));
}
