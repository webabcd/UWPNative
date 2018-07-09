#ifndef _MYHEAD_FUNCTION_
#define _MYHEAD_FUNCTION_ 

#ifdef __cplusplus  
extern "C"
#endif  

// 函数声明
// 像这种在 .h 中声明的函数，如果想被外部文件调用的话，则外部文件不用再声明即可调用
char *demo_cFunction();

long recursion(int n);

void update(int ary[], int aryLength);
// 也可以将上面的函数声明写成下面这种形式，像这种只有参数类型，没有参数名称的函数声明称之为函数原型（function prototype）
// void update(int[], int);

void demo_variable1();

void demo_variable2();

void demo_params();



// 加上 static 关键字就是内部函数，仅能在当前文件使用；在不同的文件中如果有同名的内部函数，则他们互不干扰
static void cFunction_demo1();

// 加上 extern 关键字就是外部函数，可被其他文件调用
extern void cFunction_demo2();

// 如果既无 static 也无 extern，则默认为 extern
void cFunction_demo3();

#endif