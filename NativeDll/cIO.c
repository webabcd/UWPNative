/*
 * 标准输入，标准输出
 *
 * 对系统指定的标准设备的输入和输出（即从键盘输入数据，从显示器输出数据），这种输入输出称为标准的输入输出，简称标准 I/O
 */

#include "pch.h"
#include "cIO.h"
#include "cHelper.h"

void io_printf();
void io_scanf();
void io_putchar();
void io_getchar();

char *demo_cIO()
{
	// 格式化输出 printf
	io_printf();

	// 格式化输入 scanf
	io_scanf();

	// 字符输出 putchar()
	io_putchar();

	// 字符串输入 getchar()
	io_getchar();

	return "看代码及注释吧";
}


// 格式化输出 printf
void io_printf()
{
	// printf - print formatted，以下仅列一下常用用法
	// printf 的返回值为：实际输出的字符数

	int a = 88;
	float b = 3.14159;
	char *c = "webabcd wanglei";


	// %d - 以十进制形式输出带符号整数
	// %.2f - 以浮点型输出，取小数点后 2 位（四舍五入）
	// %.7s - 以字符串输出，取前 7 位
	printf("%d, %.2f, %.7s\n", a, b, c);
	// 输出结果：88, 3.14, webabcd
	// printf 的返回值为 18


	// %o - 以八进制形式输出无符号整数
	// %#o - 以八进制形式输出无符号整数，并加前缀 0
	printf("%o, %#o\n", a, a);
	// 输出结果：130, 0130


	// %x 或 %X - 以十六进制形式输出无符号整数
	// %#x - 以八进制形式输出无符号整数，并加前缀 0x
	// %#X - 以八进制形式输出无符号整数，并加前缀 0X
	printf("%x, %#x, %#X\n", a, a, a);
	// 输出结果：58, 0x58, 0X58


	// %10.2f - 以浮点型输出，取小数点后 2 位；显示宽度至少为 10 位，不够以空格填充
	printf("%10.2f\n", b);
	// 输出结果：      3.14（前面有 6 个空格）



	/*
	 * 类型说明如下：
	 * %d / %i - 整型
	 * %o - 无符号八进制
	 * %u - 无符号十进制
	 * %x / %X - 无符号十六进制
	 * %f / %F - 浮点型
	 * %e / %E - 科学表示法（%e后面就输出小写e；%E后面就输出大写E）
	 * %g / %G - 浮点型，但是会去掉小数后面多余的 0，然后在 %f 和 %e 之中选一个最短的形式输出
	 * %c - 字符
	 * %s - 按字符串输出，直至'\0'
	 * %p - 以十六进制形式输出指针
	 * %% - %
	 *
	 *
	 * 另外有两种长度格式：
	 * h - 按短整型量输出，比如：%hd - 按短整型输出; printf("%hd", 32769) 输出结果为 -32767
	 * l - 按长整型量输出，比如：%lf - 按 double 输出; %ld - long int; %lld - long long int
	 */

	float x = 3.14f;
	printf("%f", x); // 3.140000
	printf("%g", x); // 3.14

	float y = 12345678.123456f;
	printf("%e", y); // 1.234568e+07
	printf("%f", y); // 12345678.000000
	printf("%G", y); // 1.23457E+07（另外，比 %e 少一位小数）
}


// 格式化输入 scanf
void io_scanf()
{
	// scanf - scan formatted，以下仅列一下常用用法
	// printf 的返回值为：成功接收到的赋值参数的个数

	int a;
	float b;
	char c[100];


	// %2s - 代表输入字符串时，只取前 2 位
	// 如果在两个格式化参数之间没有它字符的话，则可用空格或TAB或回车做间隔
	scanf("%d%f%2s", &a, &b, c);
	// 输入 1 3.14 webabcd 后的结果为：a 的值为 1，b 的值为 3.14，c 的前 3 个元素为 'w' 'e' '\0'
	// scanf 的返回值为 3


	// 如果在两个格式化参数之间有它字符的话，则按指定的字符做间隔
	scanf("a=%d, b=%f, c=%s", &a, &b, c);
	// 输入：a=1, b=3.14, c=webabcd
}


// 字符输出 putchar()
void io_putchar()
{
	// 输出一个字符
	putchar('a');
}


// 字符串输入 getchar()
void io_getchar()
{
	// 当程序调用 getchar() 函数时，程序就等着用户按键，用户输入的字符被存放在键盘缓冲区中，直到用户按回车为止（回车字符也放在缓冲区中）
	// 当用户键入回车之后，getchar() 函数才开始从键盘缓冲区中每次读入一个字符，一直到缓冲区中的字符读完

	/*
	char c = NULL;
	while ((c == getchar()) != '\n') 
	{
		printf("%c", c);
	}
	*/

	// getch(), getche() 之类的需要 conio.h, 但是在 linux 下是没有的，所以就不写了
}