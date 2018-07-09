// c 的 .h 文件


// 头文件一般用于放置：需要向外暴露的宏定义，全局变量声明，函数声明


// 防止同一文件的二次编译。比如你有两个 c 文件，这两个 c 文件都 include 了同一个头文件，在编译时，这两个 c 文件就会被一同编译，那么就带来了声明冲突的问题
#ifndef _MYHEAD_HELLO_ // 是 if not defined 的缩写，如果没定义 _MYHEAD_HELLO_ 则执行这一块
#define _MYHEAD_HELLO_ // 定义 _MYHEAD_HELLO_





// 在 c++ 中写 c 语言代码
#ifdef __cplusplus // 如果当前是 c++ 环境
extern "C" // 告诉 c++ 下面的 { } 块中写的是 c 语言代码
{
#endif

	// 函数声明
	char *demo_cHello(char *name);

#ifdef __cplusplus // 如果当前是 c++ 环境
}
#endif





/*
// 在 windows 环境下，可以简写成这样
#ifdef __cplusplus
extern "C"
#endif

char *demo_cHello(char *name);
*/





#endif // #ifndef _MYHEAD_HELLO_