/*
 * 指针
 */

#include "pch.h"
#include "cPointer.h"
#include "cHelper.h"


void pointer_demo1();
void pointer_demo2();
void pointer_demo3();
void pointer_demo4();
void pointer_demo5();
void pointer_demo6();
void pointer_demo7();
void pointer_demo8();
void pointer_demo9();
void pointer_demo10();

char *demo_cPointer()
{
	// 指针的基本概念
	pointer_demo1();

	// 字符串指针
	pointer_demo2();

	// 把指针做为参数传递
	pointer_demo3();

	// 数组指针的运算
	pointer_demo4();

	// 二维数组的指针
	pointer_demo5();

	// 函数指针（指向函数的指针）
	pointer_demo6();

	// 指针型函数（函数返回值可以是一个指针）
	pointer_demo7();

	// 指针数组
	pointer_demo8();

	// 指针的指针
	pointer_demo9();

	// void 类型的指针
	pointer_demo10();

	return "看代码及注释吧";
}


// 指针的基本概念
void pointer_demo1()
{
	/*
	 * 注：
	 * 1、未经赋值的指针变量不能使用
	 * 2、一个指针变量只能指向相同类型的变量，比如指针 p 如果指向了整形变量，就不能再指向字符变量或其他非整型类型的变量了
	 */


	// 定义一个指针，并将其赋值为一个空指针（对应的宏定义 #define NULL 0）。所谓空指针就是不指向任何内容的指针
	int *p_empty = NULL; // 相当于 int *p = 0;


	// 定义一个整型变量，并初始化
	int i = 100;

	// *p - 代表定义一个名为 p 的指针。此处的“*”是类型说明符，表示 p 是一个指针
	// &i - 代表取变量 i 的地址。此处的“&”是取地址运算符，表示取变量 i 的地址
	int *p = &i;

	// *p - 代表取指针 p 所指向的内容。此处的“*”是取内容运算符，表示取指针 p 所指向的内容
	int j = *p;
}


// 字符串指针
void pointer_demo2()
{
	// 定义一个字符串指针（字符串是以'\0'结尾的）
	char *p = "i am webabcd";

	// p 就是字符串指针，p + 5 所指向的结果就是 webabcd
	char *name = p + 5;
	// 字符串长度
	int length = strlen(name); // 7，不包括 '\0'
	// 指针占用的内存空间
	int memory = sizeof(name); // 我这里是 4 字节

	char *p_address = (char *)malloc(32);
	sprintf(p_address, "%p", name); // 指针 name 的地址值，我这里是 32 位的，类似 6416C99D
	free(p_address);
}


// 把指针做为参数传递
void pointer_demo3()
{
	int m = 1;
	int n = 2;

	int *x = &m;
	int *y = &n;

	// 调用 swap 后: *x = m = 2, *y = n = 1
	void swap(int *i, int *j);
	swap(x, y);
}
void swap(int *i, int *j) // 交换两个指针指向的整型值
{
	// 形参是实参的副本，被调用期间分配内存单元，调用结束立即释放
	// 对于指针来说也是这样的，只不过是 copy 了地址做为副本

	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}


// 数组指针的运算
void pointer_demo4()
{
	int ary[] = { 11, 22, 33, 44, 55, 66 };
	// 因为 ary 是数组的首地址，所以 ary == &ary[0]
	if (ary == &ary[0])
	{
		// ary 是数组的首地址，即数组第一个元素的地址，对其取内容后就是数组第一个元素的内容，结果为 11
		int x1 = *ary;

		// 数组指针是可运算的，运算的是元素在数组中的位置索引，拿 ary + 2 举例，ary 数组第 1 个元素的指针，加 2 后就是数组第 3 个元素的指针，取其内容后结果为 33
		int x2 = *(ary + 2);

		char *p0_address = (char *)malloc(32);
		sprintf(p0_address, "%p", ary); // 假定此处指针本身的值为：0535DC30 的话
		free(p0_address);

		char *p1_address = (char *)malloc(32);
		sprintf(p1_address, "%p", ary + 1); // 那么如果整型是 4 字节的话，则此处指针本身的值为 0535DC34  
		free(p1_address);
	}


	// 再来一个指针运算的例子（将字符串 str1 复制到字符串 str2）
	char str1[] = "i am webabcd", str2[20], *p1, *p2;
	p1 = str1; p2 = str2;
	for (; *p1 != '\0'; p1++, p2++)
		*p2 = *p1;
	*p2 = '\0';
	p1 = str1; p2 = str2; // 指回数组首地址
}


// 二维数组的指针
void pointer_demo5()
{
	int ary[2][6] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	// 定义一个二维数组的指针：类型说明符(*指针变量名)[列数，即二维长度]
	int(*p)[6] = ary;

	// p 就是 ary
	if (p == ary)
	{
		// 这里要好好理解（拿指针的指针去理解，ary 相当于二级指针，ary[i] 相当于一级指针）
		// ary[1] 是二维数组第 2 行的一维数组的首地址，也就是说其相当于 &ary[1][0]
		// ary + 1 指向的是 ary[1]，对其取内容 *(ary + 1) 就是 ary[1] 了
		// ary[1] = &ary[1][0] = *(ary + 1)

		// 再加深理解一下：ary 是二维数组的首地址，*ary 是二维数组第 1 行的一维数组的首地址，*(ary + 1) 是二维数组第 2 行的一维数组的首地址


		// 取第 2 行，第 6 列的数据，结果为 11
		int x = p[1][5];


		// 再加深理解一遍
		// p 是指向二维数组的指针
		// p + 1 指向的是 ary[1]，所以 *(p + 1) 就是 ary[1]
		// *(p + 1) + 5 指向的是 p[1][5]，所以 *(*(p + 1) + 5) 就是 p[1][5]，结果为 11
		int y = *(*(p + 1) + 5); 
		
		// ary[i] = *(ary+i), ary[i]+j = *(ary+i)+j, ary[i][j] = *(*(ary+i)+j)
	}
}


// 函数指针（指向函数的指针）
void pointer_demo6()
{
	// 定义一个函数指针：类型说明符(*指针变量名)();
	int(*pmax)(int a, int b);

	// 让函数指针指向函数 my_max
	int my_max(int a, int b);
	pmax = my_max;

	int x = 10, y = 100;
	// (*pmax) 就是函数 my_max，结果为 100
	int z = (*pmax)(x, y); 


	// 函数指针当然也是指针，可以取其地址
	char *p_address = (char *)malloc(32);
	sprintf(p_address, "%p", &pmax);
	free(p_address);
}
int my_max(int a, int b) // 取两个整型的最大值
{
	if (a > b)
		return a;
	return b;
}


// 指针型函数（函数返回值可以是一个指针）
void pointer_demo7()
{
	// 函数名之前加“*”号表明这是一个指针型函数，即返回值是一个指针。类型说明符表示了返回的指针值所指向的数据类型

	char *day_name(int n);
	// 结果：星期五
	char *result = day_name(5);
}
char *day_name(int n)
{
	static char *name[] =
	{ 
		"星期日",
		"星期一",
		"星期二",
		"星期三",
		"星期四",
		"星期五",
		"星期六"
	};

	return ((n < 0 || n > 6) ? "unknown" : name[n]);
}


// 指针数组
void pointer_demo8()
{
	char *str1 = "webabcd";
	char *str2 = "wanglei";

	// 定义一个指针数组，即数组中的每一个元素都是一个指针
	char *p[2] = { str1, str2 }; // str1 和 str2 都是指针

	// 结果为 wanglei
	char *x = p[1]; // p[1] - 指针数组中的第 2 个指针
}


// 指针的指针
void pointer_demo9()
{
	// 指针数组其实就是指针的指针
	char *name[] = { "webabcd", "wanglei" };

	// 通过“**”定义一个指针的指针
	char **p = name;
	p++;

	// 结果为 wanglei
	char *myName = *p; // p 是指针的指针（二级指针），*p 是指针（一级指针）
}


// void 类型的指针
void pointer_demo10()
{
	void *void_pointer();

	// void 类型的指针 - 内存中的数据的类型要由用户来指定
	char *name = (char *)void_pointer();
}
void *void_pointer() // 返回 void 类型的指针
{
	return "wanglei";
}