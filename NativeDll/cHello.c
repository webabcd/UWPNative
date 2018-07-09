/*
 * hello c
 */

#include "pch.h" // 预编译头文件
#include "cHello.h" // 引入需要实现的头文件
#include "cHelper.h" // 引入自定义函数的头文件

char *demo_cHello(char *name)
{
	return str_concat2("hello: ", name);
}



// 本 demo 无法演示 main 函数，所以以下做一些关于 main 函数的文字说明

// main 函数是入口函数，不能被其它函数调用
// 假设命令为：可执行文件名 参数1 参数2 参数3
int main(int argc, char *argv[]) // main 函数也可以是无参无返回值的，即：int main(void) { } 或 void main(void) { } 都是可以的
{
	// argc 是参数个数；argv 是参数值

	// argc - 等于 4 （注：“可执行文件名”也算一个参数）
	// argv[0] - 可执行文件名; argv[1] - 参数1; argv[2] - 参数2; argv[3] - 参数3
	
	// 返回 0 代表正常
	return 0; 
}