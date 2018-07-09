/*
 * 数组
 *
 *
 * 定义数组，int ary[10]，相关说明如下：
 * 1、int 是数据元素的数据类型，10 是数组元素个数，系统会根据数组元素的数据类型和元素个数来分配内存空间
 * 2、整个数组是以首地址开头的一块连续的内存单元
 * 3、数组名 ary 就代表了该数组的首地址，也就是说 ary 相当于 &ary[0]
 */

#include "pch.h"
#include "cArray.h"
#include "cHelper.h"

char *demo_cArray()
{
	// 定义并初始化一个数组
	// int ary[] = { 0, 1, 2, 3, 4 };

	// 定义一个长度为 10 的数组，并初始化前 5 个元素，其他元素默认为 0
	// 注：定义数组的长度时必须用常量，不能用变量（注：ANSI C99 是允许用变量定义局部数组大小的）
	int ary[10] = { 0, 1, 2, 3, 4 };
	// 修改数组中某一个元素的值（注：只能对数组的元素赋值，而不能用赋值语句对整个数组赋值）
	ary[8] = 0;

	// sizeof(ary) - 数组 ary 占用的内存空间
	// 由于 ary 是一个整型数组，而每个整型数据占用 sizeof(int) 个字节的空间，则数组元素的个数为 sizeof(ary) / sizeof(int)
	int count = sizeof(ary) / sizeof(int);
	for (int i = 0; i < count; i++)
	{
		int x = ary[i];
	}



	// 指定行数（一维长度）和列数（二维长度）定义一个二维数组，并初始化
	int ary2[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	// 修改二维数组中某一个元素的值
	ary2[0][1] = 2;

	// 初始化二维数组时，也可以一行一行地按顺序写入数据，如下。其结果同上
	// int ary2[3][2] = { 1, 2, 3, 4, 5, 6 };

	// 定义二维数组时，可以省略行数（一维长度），如下。其结果同上
	// int ary2[][2] = { 1, 2, 3, 4, 5, 6 };

	// 遍历二维数组
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int x = ary2[i][j];
		}
	}



	// 定义一个字符数组，并初始化
	// char aryStr[] = { 'i', ' ', 'a', 'm', ' ', 'w', 'e', 'b', 'a', 'b', 'c', 'd' }; // 长度12，占用空间12

	// 定义一个字符数组，并按字符串的形式对其初始化
	// char aryStr[] = { "i am webabcd" }; 同 char aryStr[] = "i am webabcd"; // 长度12，占用空间13

	// 以字符串的形式赋值给字符数组时，会自动在结尾处多加一个字符串结束符，即'\0'，用于标记字符串结束（字符串的结束标识为：'\0'，即 ASCII 码中的 0，也就是 NULL）
	char aryStr[] = "i am webabcd";

	// 字符串长度
	int length = strlen(aryStr); // 12
	// 字符串占用的内存空间（如果 aryStr 赋值给别人，或当做参数传递时，其就表现为数组的首地址了，如果再对其 sizeof 的话，取得的就是指针所占用的内存空间的大小）
	int memory = sizeof(aryStr); // 13

	/*
	 * 注意：
	 * 1、此处通过 sizeof(aryStr) 获取到的是数组的空间占用，通过 strlen(aryStr) 获取到的是数组的长度
	 * 2、然而之前我们说过，数组名 aryStr 就是数组的首地址，整个数组是以首地址开头的一块连续的内存单元
	 * 3、当我们把 aryStr 赋值给别人（比如 char *s = aryStr;），或当做参数传递时，其就表现为数组的首地址了。比如在对应的形参中，如果 sizeof(ary) 的话，其得到的是指针占用的内存空间的大小
	 */


	/*
	 * 另：
	 * 1、如果你知道了一个字符串的首地址，那么你就知道这个字符串的长度，因为它会以“0”结尾
	 * 2、如果你知道一个普通数组的首地址，那么你是不知道这个数组的长度的，因为你不知道它在哪里结尾
	 */



	// 写到数组了，就用“冒泡排序”举个例子吧
	// 记得以前去某公司 C# 笔试，题目是对一个数组排序，我写的是
	/*
	int[] ary = { 1, 9, 5, 6, 3 };
	ary = ary.OrderBy(p => p).ToArray();
	*/
	// 结果面试官说这个不对...
	void bubble_sort(int ary[], int length);
	int ary_int[] = { 14, 80, 19, 6, 26, 2 };
	bubble_sort(ary_int, 6); // 2, 6, 14, 19, 26, 80


	return str_concat2(int_toString(length), int_toString(memory));
}


// 冒泡排序算法
void bubble_sort(int ary[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		bool sorted = true;

		for (int j = 0; j < length - 1 - i; j++)
		{
			if (ary[j] > ary[j + 1])
			{
				sorted = false;
				int temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}

		if (sorted)
			break;
	}
}


/*
写到 for 循环，然后发现一个事情


for(int i=0;;) 这个在 C99 下是合法的

而以前的标准 for(int i=0;;) 是不合法的（不能在语句中声明变量），需要这么写
int i;
for(i=0;;);
*/