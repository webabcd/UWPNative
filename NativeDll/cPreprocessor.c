/*
 * 预处理命令
 *
 * 以“#”开头的就是预处理命令（预处理命令不用“;”结尾），其是指在编译之前所做的工作
 */

#include "pch.h"
#include "cPreprocessor.h"
#include "cHelper.h"



// #define - 宏定义命令，在编译预处理时，对程序中所有出现的“宏名”，都用宏定义中的字符串去代换，这称为“宏代换”或“宏展开”
#define PI 1000 //  #define 标识符 字符串
#define S PI * r * r // 一个宏也可以引用另一个宏
#define S2(r) PI * r * r // 宏是可以带参数的
#define PI 3.14 // 宏重名的话，后面的会替换前面的
#define INTEGER int // 宏定义当然也可以定义数据类型，因为其本质就是拿一个字符串替换另一个字符串
#define ISWINDOWS 1
#define X(n) n == 0 ? 0 \
	: -1 // 一个长的 #define 可以用“\”分成多行


// 说到这里再插一句，单行注释的话 \
以“\”结尾则下一行也为注释 \
另外：ANSI C 只支持“/**/”注释，而不支持“//”注释


/*
再强调一遍，宏替换的本质就是拿一个字符串替换另一个字符串

如果是 #define x 1 + 2
那么表达式 3 * x * 4 就相当于 3 * 1 + 2 * 4，结果是 11
如果是 #define x (1 + 2)
那么表达式 3 * x * 4 就相当于 3 * (1 + 2) * 4，结果是 36
*/



/*
#include - 文件包含命令

#include "stdio.h" 使用双引号表示首先在文件当前目录中查找（支持绝对路径和相对路径），若未找到则到包含目录中去查找
#include <math.h> 使用尖括号表示在包含文件目录中去查找，而不在文件当前目录去查找

包含文件目录的设置：项目 -> 右键 -> 属性 -> 配置属性 -> VC++ 目录 -> 包含目录
*/



char *demo_cPreprocessor()
{
	INTEGER r = 2; // 宏展开其相当于 int r = 2;
	float x = S; // 宏展开其相当于 3.14 * r * r，即 3.14 * 2 * 2

	float y = S2(2); // 宏展开其相当于 3.14 * 2 * 2

	int z = X(100); // -1

	

// 条件编译命令有：#ifdef, #else, #endif, #ifndef, #if
#ifdef PI // 如果在宏定义中定义了 PI（ifdef 是 if defined 的简写）
	;
#else // 如果不需要的话，可以不要 #else
	;
#endif  // #ifdef 和 #endif 必须成对


#ifndef PI // 如果在宏定义中没有定义 PI（ifndef 是 if not defined 的简写）
	;
#else // 如果不需要的话，可以不要 #else
	;
#endif // #ifndef 和 #endif 必须成对


#if ISWINDOWS // 如果宏定义 ISWINDOWS 非零则为真（ISWINDOWS 是整型）
	;
#else // 如果不需要的话，可以不要 #else
	;
#endif // #if 和 #endif 必须成对



	return float_toString(y);
}


// 这之后不再有 PI 这个宏定义（undef 是 undefine 的简写）
#undef PI