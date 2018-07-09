#include "pch.h"
#include "cHelper.h"
#include <string.h>  


char *str_concat2(const char *str1, const char *str2)
{
	char *result;
	result = (char *)malloc(strlen(str1) + strlen(str2) + 1); //str1的长度 + str2的长度 + \0;
	if (!result) // 如果内存动态分配失败
	{
		printf("Error: malloc failed in concat! \n");
		exit(EXIT_FAILURE);
	}

	strncpy(result, str1, strlen(str1) + 1);
	strncat(result, str2, strlen(str1) + strlen(str2) + 1); //字符串拼接
	return result; // 外面调用后别忘了 free 掉
}

char *str_concat3(const char *str1, const char *str2, const char *str3)
{
	return str_concat2(str_concat2(str1, str2), str3);
}

char *str_concat4(const char *str1, const char *str2, const char *str3, const char *str4)
{
	return str_concat2(str_concat3(str1, str2, str3), str4);
}

char *str_concat5(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5)
{
	return str_concat2(str_concat4(str1, str2, str3, str4), str5);
}


char *int_toString(int i)
{
	char *result = (char *)malloc(32); 
	sprintf(result, "%d", i);
	return result;
}

char *float_toString(float f)
{
	char *result = (char *)malloc(32);
	sprintf(result, "%f", f);
	return result;
}