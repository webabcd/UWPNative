/*
 * 文件
 *
 * 从用户角度讲，文件可分为普通文件和设备文件两种
 * 1、普通文件是指保存在磁盘或其它外部介质上的一段数据
 * 2、设备文件是指与主机相联的各种外部设备，操作系统会把各种外部设备也看作是一个文件来进行管理。比如：通常把显示器定义为标准输出文件，键盘定义为标准输入文件
 *
 * 从文件编码的方式来看，文件可分为 ASCII 码文件（文本文件）和二进制文件
 * 1、ASCII 文件也称为文本文件，这种文件在磁盘中存放时每个字符对应一个字节，用于存放对应的 ASCII 码。比如：字符串 1234567 按字符存放成文本文件，占用 7 个字节
 * 2、二进制文件是按二进制的编码方式来存放文件的。比如：数字 1234567 按整型存放成二进制文件，占用 4 个字节
 *
 * 关于 mkdir(make directory) - 创建目录，rmdir(remove directory) - 删除目录 之类的函数，以后再写
 *
 *
 * 注：EOF（end of file） - 文件的结束标志
 */

#include "pch.h"
#include "cFile.h"
#include "cHelper.h"

void file_demo1();
void file_demo2();
void file_demo3();
void file_demo4();
void file_demo5();

char *_rootPath;

char *demo_cFile(char *rootPath)
{
	_rootPath = rootPath;

	// 写入文本文件
	file_demo1();

	// 读取文本文件
	file_demo2();

	// 以格式化的方式读写文本文件
	file_demo3();

	// 读写二进制文件
	file_demo4();

	// 文件的内部定位（随机读写，即任意位置读写）
	file_demo5();

	return str_concat2("演示文件的保存路径：", rootPath);
}


// 写入文本文件
void file_demo1()
{
	// 文件指针 - 指向文件的指针（FILE *指针变量标识符）


	// 需要访问的文件路径
	char *fileName = str_concat2(_rootPath, "\\c_file_demo1.txt");

	// fopen - 用指定的方式打开指定路径的文件，并返回文件指针（FILE 是由系统定义的结构体，fp 是指向 FILE 的文件指针）
	FILE *fp = fopen(fileName, "wt+"); // 第 2 个参数是文件打开方式，其说明参见后面的注释
	if (fp == NULL)
	{
		// 如果 fopen 返回空指针，则说明文件打开失败（errno 中保存着最近一次的错误）
		int errNum = errno; // 关于 errno 的预定义参见 errno.h
	}
	else
	{
		// rewind - 让指定的文件指针所指文件的内部位置指针移到文件头
		rewind(fp);

		// fputc - 向指定的文件写入字符（这里的 EOF 代表写入失败）
		if (fputc('w', fp) == EOF) 
		{
			// ferror - 检查文件在读写时是否出错，返回值为 0 表示正常，否则表示有错
			int errNum = ferror(fp); // 关于 errno 的预定义参见 errno.h

			// clearerr - 清除出错标志，使它为 0 值。
			clearerr(fp);
		}

		// fputs - 向指定的文件写入字符串（这里的 EOF 代表写入失败）
		if (fputs("ebabcd\nwanglei", fp) == EOF)
		{
			// ferror - 检查文件在读写时是否出错，返回值为 0 表示正常，否则表示有错
			int errNum = ferror(fp); // 关于 errno 的预定义参见 errno.h

			// clearerr - 清除出错标志，使它为 0 值。
			clearerr(fp);
		}

		// fclose - 打开文件后，必须要用 fclose 关闭文件，返回 0 则说明文件正常关闭了
		int fcloseResult = fclose(fp);
	}

	free(fileName);
}


// 读取文本文件
void file_demo2()
{
	char *fileName = str_concat2(_rootPath, "\\c_file_demo1.txt");

	FILE *fp = fopen(fileName, "rt");
	if (fp == NULL)
	{
		int errNum = errno;
	}
	else
	{
		rewind(fp);

		// fgetc - 一个字符一个字符地读，如遇到 EOF 则文件读完或出错（每个文件末尾都有结束标志 - EOF）
		char ch = fgetc(fp);
		while (ch != EOF)
		{
			// 每读一个字符，则内部位置指针会向后移动一个字节
			ch = fgetc(fp); 
		}

		// feof - 检查文件是否结束（即内部位置指针是否指向 EOF），如结束，则返回非零值，否则返回 0
		int isEnd = feof(fp); // 非零值

		rewind(fp);

		// feof - 检查文件是否结束（即内部位置指针是否指向 EOF），如结束，则返回非零值，否则返回 0
		isEnd = feof(fp); // 0

		/*
		 * fgets(str, n, fp) - 读取字符串函数
		 *     str - 字符数组名，由于保存读取到的字符串
		 *     n - 读出 n-1 个字符并送入字符数组 str 中，然后在结尾加'\0'（在读出 n-1 个字符之前，如遇到了换行符或 EOF，则读取结束）
		 *     fp - 文件指针
		 */
		char str[32];
		while (fgets(str, 32, fp) != NULL)
		{
			// 本例会循环 2 次
			// 第 1 次 str 的结果为：webabcd\n
			// 第 2 次 str 的结果为：wanglei
		}

		fclose(fp);
	}

	free(fileName);
}


// 以格式化的方式读写文本文件
void file_demo3()
{
	char *fileName = str_concat2(_rootPath, "\\c_file_demo2.txt");

	FILE *fp = fopen(fileName, "wt+");
	if (fp == NULL)
	{
		int errNum = errno;
	}
	else
	{
		// fprintf(file print formatted) - 以格式化的方式写入字符串（返回值为写入的字节数）
		int fprintfResult = fprintf(fp, "%s %d %d\n", "webabcd", 100, 20); // 15

		rewind(fp);

		int num;
		int age;
		char name[32];

		// fscanf(file scan formatted) - 以格式化的方式读取字符串（返回值为读取的成员数）
		int fscanfResult = fscanf(fp, "%s %d %d\n", name, &num, &age); // 3

		fclose(fp);
	}

	free(fileName);
}


// 读写二进制文件
void file_demo4()
{
	struct employee
	{
		int num;
		char name[32];
	} w[2] = { { 100, "wanglei" }, { 200, "webabcd" } }, r[2], *ww, *rr;

	ww = w;
	rr = r;

	char *fileName = str_concat2(_rootPath, "\\c_file_demo3.b");

	FILE *fp = fopen(fileName, "wb+");
	if (fp == NULL)
	{
		int errNum = errno;
	}
	else
	{
		/*
		 * fwrite(buffer, size, count, fp) - 写入二进制数据（返回值为成功写入的数据块数）
		 *     buffer - 需要写入的数据的指针
		 *     size - 每一个数据块的字节数
		 *     count - 需要写入的数据块数
		 *     fp - 文件指针
		 */
		int fwriteResult = fwrite(ww, sizeof(struct employee), 2, fp); // 2

		rewind(fp);

		/*
		 * fread(buffer, size, count, fp) - 读取二进制数据（返回值为成功读取的数据块数）
		 *     buffer - 需要保存读取数据的指针
		 *     size - 每一个数据块的字节数
		 *     count - 需要读取的数据块数
		 *     fp - 文件指针
		 */
		int freadResult = fread(rr, sizeof(struct employee), 2, fp);

		fclose(fp);
	}

	free(fileName);
}


// 文件的内部定位（随机读写，即任意位置读写）
void file_demo5()
{
	struct employee
	{
		int num;
		char name[32];
	} w[2] = { { 100, "wanglei" }, { 200, "webabcd" } }, r[1], *ww, *rr;

	ww = w;
	rr = r;

	char *fileName = str_concat2(_rootPath, "\\c_file_demo4.b");

	FILE *fp = fopen(fileName, "wb+");
	if (fp == NULL)
	{
		int errNum = errno;
	}
	else
	{
		int fwriteResult = fwrite(ww, sizeof(struct employee), 2, fp);

		/*
		 * rewind(fp) - 把文件内部位置指针移到文件头
		 *     fp - 文件指针
		 */
		rewind(fp);

		/*
		 * fseek(fp, offset, origin) - 移动文件内部位置指针
		 *     fp - 文件指针
		 *     offset - 相对于 origin 的位移字节数（长整形，如果用常量的话记得加“L”）
		 *     origin - 位移起始点
		 *         SEEK_SET（0） - 文件头
		 *         SEEK_CUR（1） - 当前位置
		 *         SEEK_END（2） - 文件尾
		 */
		fseek(fp, sizeof(struct employee), SEEK_SET);

		int freadResult = fread(rr, sizeof(struct employee), 1, fp); // 200, "webabcd"

		fclose(fp);
	}

	free(fileName);
}



/*
 * 关于文件打开方式的说明，即 fopen 的第 2 个参数 
 * rt	 只读打开一个文本文件，只允许读数据
 * wt	 只写打开或建立一个文本文件，只允许写数据
 * at	 追加打开一个文本文件，并在文件末尾写数据
 * rb	 只读打开一个二进制文件，只允许读数据
 * wb	 只写打开或建立一个二进制文件，只允许写数据
 * ab	 追加打开一个二进制文件，并在文件末尾写数据
 * rt+	 读写打开一个文本文件，允许读和写
 * wt+	 读写打开或建立一个文本文件，允许读写
 * at+	 读写打开一个文本文件，允许读，或在文件末追加数据
 * rb+	 读写打开一个二进制文件，允许读和写
 * wb+	 读写打开或建立一个二进制文件，允许读和写
 * ab+	 读写打开一个二进制文件，允许读，或在文件末追加数据
 *
 * 关于上面字符的说明
 * r(read)		读
 * w(write)		写
 * a(append)	追加
 * t(text)		文本文件，可省略不写
 * b(binary)	二进制文件
 * +			读和写
 */