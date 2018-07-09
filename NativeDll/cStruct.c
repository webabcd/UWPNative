/*
 * 结构体，共用体，枚举，类型定义符
 *
 * 注：结构体变量在做参数传递时，其内每个成员都会被传递，会降低效率。所以一般通过结构体指针传递
 */


#include "pch.h"
#include "cStruct.h"
#include "cHelper.h"


void struct_demo1();
void struct_demo2();
void struct_demo3();
void struct_demo4();

void union_demo();

void enum_demo1();

void typedef_demo1();


// 定义一个名为 birth 的结构体类型
/*
 * struct 结构名
 * {
 *     成员表列
 * };
 */
struct birth
{
	int year; // 结构体成员
	int month; // 结构体成员
	int day; // 结构体成员
};


char *demo_cStruct()
{
	// 结构体基础 1
	struct_demo1();

	// 结构体基础 2
	struct_demo2();

	// 结构体指针（指向结构体变量的指针）
	struct_demo3();

	// 结构体数组
	struct_demo4();


	// 共用体（联合体）
	union_demo();


	// 枚举
	enum_demo1();


	// 类型定义符
	typedef_demo1();


	return "看代码及注释吧";
}


// 结构体基础 1
void struct_demo1()
{
	// 定义一个名为 employee 的结构体类型
	struct employee
	{
		int num; // 结构体成员
		char *name = "unknown"; // 结构体成员，可以为其设置默认值（c++）
		float sarlary; // 结构体成员
		struct birth birthday; // 结构体成员，可以是另一个结构体
	};

	// 声明一个 employee 类型的结构体
	struct employee employee1;

	// 为结构体赋值（访问结构体成员通过“.”来实现）
	employee1.num = 100;
	employee1.name = "webabcd";
	employee1.sarlary = 100.5f;
	employee1.birthday.year = 1980;
	employee1.birthday.month = 2;
	employee1.birthday.day = 14;

	// 占用内存空间为 24 字节
	int size = sizeof(struct employee);
}


// 结构体基础 2
void struct_demo2()
{
// 常用的结构体类型可以用宏定义来表示（也可以用 typedef, 后面再说）
#define EMPLOYEE struct employee
	EMPLOYEE
	{
		int num;
		char *name;
	} employee1, employee2 = { 100, "webabcd" }; // 声明结构体变量的时候就可以对其初始化
	EMPLOYEE employee3 = { 100, "webabcd" };

	// 针对指定的成员做初始化（这个在 vs 里没调通，在 xcode 是可以的）
	// struct employee emp = { .name = "webabcd" };

	// 在定义结构体类型的时候，就声明变量的话，可以省去结构体名
	struct
	{
		int num;
		char *name;
	} employee4, employee5 = { 100, "webabcd" }; // 声明结构体变量的时候就可以对其初始化


	// 相同类型的结构体是可以互相赋值的，其成员无论是基本类型还是指针都会复制出一份新的
	employee1 = employee2;
	employee2.num = 99;
	employee2.name = "wanglei";
	// 结果：employee1（num=100, name="webabcd"）, employee2（num=99, name="wanglei"）
}


// 结构体指针（指向结构体变量的指针）
void struct_demo3()
{
	struct employee
	{
		int num;
		char *name;
	};

	struct employee employee1 = { 100, "webabcd" };
	
	// 定义一个结构体指针（指向结构体变量的指针）
	struct employee *employee = &employee1;

	char *name = employee1.name;

	// (*employee) - 是结构体指针所指向的结构体内容
	name = (*employee).name;

	// 如果通过结构体指针访问结构体指针所指向的结构体的成员的话，通过“->”来实现
	name = employee->name;
}


// 结构体数组
void struct_demo4()
{
	struct employee
	{
		int num;
		char *name;
	};

	// 定义一个结构体数组
	struct employee employees[2] =
	{
		{ 100, "webabcd" },
		{ 200, "wanglei" }
	};

	// 结构体数组和指针的关系，与一般数组和指针的关系是一样的
	struct employee *employee1 = employees;
	struct employee *employee2 = &employees[0];
}


// 共用体（联合体）
void union_demo()
{
	// 所谓共用体，就是让几个变量共用一个内存空间，共用体占用空间大小为该共用体最大基本类型成员的整倍数，且大小要正好包含住共用体最大类型成员
	// 注：以下如果有列出结果的，均为我的环境的结果。比如我这里 int 是占用 4 个字节的

	union u // 占用 4 个字节（a 占用 4 个字节，b 占用 4 个字节，由于他们共用一个内存空间，所以这个共用体占用 4 个字节）
	{
		int a;
		int b;
	} u1;

	u1.a = 1;
	u1.b++;
	// 上面执行后的结果是 u1.a 等于 2，u1.b 等于 2，因为他们是共用一个内存空间



	union // 占用 12 个字节（a 占用 4 个字节，b 占用 10 个字节，该共用体最大基本类型为 int，它占 4 个字节，以它来对齐，则这个共用体占用 12 个字节）
	{
		int a; // 共用体最大基本类型成员
		char s[10]; // 共用体最大类型成员
	} u2;

	u2.a = 0x61626364; // abcd
	char s1 = u2.s[0]; // d
	char s2 = u2.s[0]; // c
	char s3 = u2.s[0]; // b
	char s4 = u2.s[0]; // a
	// 由上可见，我的 cpu 是小端模式，即高地址存高字节，低地址存低字节
	// 注：网络字节顺序是按大端模式，即高位数据存放在低位地址（可以通过 ntohs, ntohl, htons, htonl 做转换）
}


// 枚举
void enum_demo1()
{
	/*
	 * enum 枚举名
	 * {
	 *     枚举值表
	 * };
	 */

	// 定义一个名为 weekday 的枚举类型
	enum weekday
	{
		sun, mon, tue, wed, thu, fri, sat
	} a, b, c = fri; // 声明并初始化枚举变量

	// 声明一个 weekday 类型的枚举变量，并初始化
	weekday d = sat; // 枚举值不是字符串呦

	// 判断一个枚举值的话，可以用枚举值或枚举值索引
	if (d == sat && d == 6)
	{
		// 用枚举值索引复制枚举值时，需要强制类型转换
		weekday e = (enum weekday)3; // wed
	}
	

	// 在定义枚举类型的时候，就声明变量的话，可以省去枚举名
	enum
	{
		v1, v2, v3
	} e1, e2, e3 = v3;
}


// 类型定义符
void typedef_demo1()
{
	// typedef - 类型定义符


	// INTEGER 类型就是 int 类型
	typedef int INTEGER;
	INTEGER a, b;

	// INTP 类型就是指向 int 类型的指针
	typedef int* INTP;

	// NAME 类型就是长度为 20 的 char 数组
	typedef char NAME[20];
	NAME a1, a2;

	// STR 类型就是 char 指针
	typedef char *STR;
	STR s1, s2;

	// EMP 类型就是 struct employee 结构体
	typedef struct employee
	{
		int num;
		char *name;
	} EMP;
	EMP emp1 = { 100, "webabcd" };


	// 注：宏定义是字符串替换，typedef 是类型替换；宏定义是由预处理完成的，typedef 则是在编译时完成的
}