/*
 * 文件
 */

#include "pch.h" 
#include "CppIO2.h" 

#include <fstream> // ifstream(继承自istream), ofstream(继承自ostream)

using namespace NativeDll;

void cppio2_demo1();
void cppio2_demo2();
void cppio2_demo3();
void cppio2_demo4();

string _rootPath;

string CppIO2::Demo(string rootPath)
{
	_rootPath = rootPath;

	// 写入文本文件
	cppio2_demo1();

	// 读取文本文件
	cppio2_demo2();

	// 写入二进制文件
	cppio2_demo3();

	// 读取二进制文件
	cppio2_demo4();
	

	return "演示文件的保存路径：" + _rootPath;
}



// 写入文本文件
void cppio2_demo1()
{
	string fileName = _rootPath + "\\cpp_file_demo1.txt";

	// 打开文件
	// ofstream outfile;
	// outfile.open(fileName, ios::out);

	// 打开文件也可以这样写
	ofstream outfile(fileName, ios::out); // 第 2 个参数是文件的输入输出方式（多个用“|”分隔），其说明参见后面的注释
	// 如果既想写又想读就用 fstream

	if (!outfile) // 如果文件打开失败，返回值为 0
	{
		// err
	}

	for (int i = 0; i < 3; i++)
	{
		// 写入文本数据
		outfile << "abc" << "\n";
	}   

	// 格式化写入的文本数据
	outfile << hex << 100 << std::endl; // 关于格式化请参见：CppIO1.cpp

	// 关闭文件
	outfile.close();       
}



// 读取文本文件
void cppio2_demo2()
{
	string fileName = _rootPath + "\\cpp_file_demo1.txt";

	char buf[1024];
	string result;
	ifstream infile(fileName, ios::in);  // 第 2 个参数是文件的输入输出方式（多个用“|”分隔），其说明参见后面的注释
	// 如果既想写又想读就用 fstream

	// 文件打开成功,说明这个文件之前是存在的
	if (infile.is_open())
	{
		// 返回下一个字符，但是文件内部位置指针不变
		char c = infile.peek(); // 如果返回的字符是文件结束符，则其值为 EOF

		// 文件正常，且文件内部位置指针不在结尾
		while (infile.good() && !infile.eof()) // eof - end of line
		{
			memset(buf, 0, 1024); // 清空 buf
			infile.getline(buf, 1204); // 读当前文件内部位置指针所指的一行数据给 buf, 然后文件内部位置指针指向下一行

			result += buf;
			result += "\n";
		}

		infile.close();
	}
}



// 写入二进制文件
void cppio2_demo3()
{
	struct employee
	{
		int num;
		char name[32];
	} w[3] = { { 100, "wanglei" }, { 200, "webabcd" }, { 300, "diandian" } };

	string fileName = _rootPath + "\\cpp_file_demo2.b";
	ofstream outfile(fileName, ios::binary); // 第 2 个参数是文件的输入输出方式（多个用“|”分隔），其说明参见后面的注释
	// 如果既想写又想读就用 fstream
	if (!outfile)
	{
		// err
	}

	for (int i = 0; i < 3; i++)
	{
		// 写入数据（要将地址转换为 char* 类型指针）
		outfile.write((char *)&w[i], sizeof(w[i]));
	}

	outfile.close();
}



// 读取二进制文件
void cppio2_demo4()
{
	struct employee
	{
		int num;
		char name[32];
	} r[2];

	string fileName = _rootPath + "\\cpp_file_demo2.b";
	ifstream infile(fileName, ios::binary); // 第 2 个参数是文件的输入输出方式（多个用“|”分隔），其说明参见后面的注释
	// 如果既想写又想读就用 fstream
	if (!infile)
	{
		// err
	}

	// 移动文件内部位置指针。关于文件内部位置指针的操作函数请参见后面的注释
	infile.seekg(sizeof(employee), ios::cur);

	for (int i = 0; i < 2; i++)
	{
		// 读取数据（要将地址转换为 char* 类型指针）
		infile.read((char *)&r[i], sizeof(r[i]));
	}

	infile.close();
}



/*
 * 文件的输入输出方式：
 *
 * ios::in - 以输入方式打开文件
 * ios::out -以输出方式打开文件（这是默认方式），如果已有此名字的文件，则将其原有内容全部清除
 * ios::app - 以输出方式打开文件，写入的数据添加在文件末尾
 * ios::ate - 打开一个已有的文件，文件指针指向文件末尾
 * ios::trunc - 打开一个文件，如果文件已存在，则删除其中全部数据，如文件不存在，则建立新文件。如已指定了 ios::out 方式，而未指定 ios::app, ios::ate, ios::in, 则同时默认此方式
 * ios::binary - 以二进制方式打开一个文件，如不指定此方式则默认为 ASCII 方式
 * ios::in | ios::out - 以输入和输出方式打开文件，文件可读可写
 * ios::out | ios::binary - 以二进制方式打开一个输出文件
 * ios::in | ios::binar - 以二进制方式打开一个输入文件
 */



/*
 * 文件内部位置指针的操作函数：
 *
 * gcount() - 返回最后一次输入所读入的字节数
 * tellg() - 返回输入文件指针的当前位置
 * seekg(文件中的位置) - 将输入文件中指针移到指定的位置
 * seekg(位移量, 参照位置) - 以参照位置为基础移动若干字节
 * tellp() - 返回输出文件指针当前的位置
 * seekp(文件中的位置) - 将输出文件中指针移到指定的位置
 * seekp(位移量, 参照位置) - 以参照位置为基础移动若干字节
 *
 *
 *
 * 参照位置的说明：
 * ios::beg - 文件开头(beg 是 begin 的缩写)，这是默认值
 * ios::cur - 指针当前的位置(cur 是 current 的缩写)
 * ios::end - 文件末尾
 */