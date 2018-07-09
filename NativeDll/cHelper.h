#ifndef _MYHEAD_HELPER_ 
#define _MYHEAD_HELPER_ 

#ifdef __cplusplus  
extern "C"
#endif  

/**
 ** 拼接字符串
 ** str1 - 字符串1, str2 - 字符串2
 ** 注：C 语言不支持函数重载（但其实本例是可以函数重载的，因为是在 C++ 环境下）
 **/
char *str_concat2(const char *str1, const char *str2);
char *str_concat3(const char *str1, const char *str2, const char *str3);
char *str_concat4(const char *str1, const char *str2, const char *str3, const char *str4);
char *str_concat5(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5);

char *int_toString(int i);

char *float_toString(float f);

#endif  