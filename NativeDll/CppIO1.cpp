/*
 * 标准输入，标准输出
 *
 * 对系统指定的标准设备的输入和输出（即从键盘输入数据，从显示器输出数据），这种输入输出称为标准的输入输出，简称标准 I/O
 */

#include "pch.h" 
#include "CppIO1.h" 

#include <iostream> // 标准输入输出的类
#include <iomanip> // io manipulator

using namespace NativeDll;

void cppio1_demo1();
void cppio1_demo2();
void cppio1_demo3();
void cppio1_demo4();
void cppio1_demo5();

string CppIO1::Demo()
{
	// cin 和 cout 的基本用法
	// cppio1_demo1();

	// 通过 cout 格式化输出
	// cppio1_demo2();

	// cout.put(), cin.get(), cin.getline()
	// cppio1_demo3();

	// cerr, clog
	// cppio1_demo4();

	// cin.ignore(), cin.putback()
	// cppio1_demo5();


	return "看代码及注释吧";
}



// cin 和 cout 的基本用法
void cppio1_demo1()
{
	// cin(console input) - 其是类型为 istream 的对象
	// cout(console output) - 其是类型为 ostream 的对象

	int a, b;
	// 输入
	std::cin >> a >> b;

	// 输出
	std::cout << a << b << "\n"; // 遇到"\n"则会把cout缓冲区中的数据输出出来
	std::cout << a << b << std::endl; // endl(end of line) - 输出"\n", 然后 flush 缓冲区

	std::cout << a;
	std::cout.flush(); // 调用 flush 也会把cout缓冲区中的数据输出出来
}



// 通过 cout 格式化输出
void cppio1_demo2()
{
	int a = 100;

	// 通过格式标志格式化输出
	std::cout << std::dec << a << std::endl; // 100 十进制
	std::cout << std::hex << a << std::endl; // 64 十六进制
	std::cout << std::oct << a << std::endl; // 144 八进制
	std::cout << std::showbase << std::uppercase << std::hex << a << std::endl; // 0X64

	/*
	 * 格式标志及说明如下：
	 *
	 * left - 输出数据在本域宽范围内向左对齐
	 * right - 输出数据在本域宽范围内向右对齐
	 * internal - 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充
	 * dec - 十进制
	 * oct - 八进制
	 * hex - 十六进制
	 * showbase - 强制输出整数的基数(八进制数以0打头，十六进制数以0x打头)
	 * showpoint - 强制输出浮点数的小点和尾数0
	 * uppercase - 在以科学记数法格式E和以十六进制输出字母时以大写表示
	 * showpos - 对正数显示“+”号
	 * scientific - 浮点数以科学记数法格式输出
	 * fixed - 浮点数以定点格式(小数形式)输出
	 * unitbuf - 每次输出之后刷新所有的流
	 */



	float b = 123.14159265f;
	// 通过 cout 的成员函数或控制符（manipulator）格式化输出
	std::cout.width(10); // 宽度为 10 个字符（仅对其后的第 1 个输出项有效）
	std::cout.precision(4); // 从第 1 个非 0 值开始，保留 4 位数字
	std::cout << b << b << std::endl; //      123.1123.1
	std::cout << std::setw(10) << b << b << std::endl; //      123.1123.1

	std::cout.setf(std::ios::hex | std::ios::showbase | std::ios::uppercase); // 设置指定的格式标志，用“|”分开
	std::cout << a << std::endl; // 0X64
	std::cout << a << std::endl; // 0X64

	std::cout.unsetf(std::ios::showbase | std::ios::uppercase); // 清除指定的格式标志，用“|”分开
	std::cout << a << std::endl; // 64

	/*
	 * 第1列是cout的成员函数；第2列是对应的控制符（要使用控制符，则须包含 iomanip 头文件）；第3列是对应的说明
	 * precision(n) setprecision(n) 从第 1 个非 0 值开始，需要输出的位数（四舍五入）
	 * width(n)     setw(n)         输出的宽度（仅对其后的第 1 个输出项有效）
	 * fill(c)      setfill(c)      填充指定宇符
	 * setf()       setiosflags()   设置指定的格式标志
	 * unsetf()     resetioflags()  清除指定的格式标志
	 */
}



// cout.put(), cin.get(), cin.getline()
void cppio1_demo3()
{
	// cout.put()
	std::cout.put(65); // A
	std::cout.put('A'); // A
	std::cout << std::endl;


	// cin.get()
	char c[100];
	// 以下面这句为例，当程序调用 cin.get() 函数时，程序就等着用户按键，用户输入的字符被存放在缓冲区中，直到用户输入'\n'为止（'\n'也放在缓冲区中）
	// 然后将字符 x 之前的 10-1 个字符赋值给 c，c 的第 10 个字符为字符串的结束标识符'\0'
	// x 以及 x 之后的字符仍然保存在缓冲区中
	std::cin.get(c, 10, 'x'); // 还有几个重载，看文档吧
	std::cout << c << std::endl;
	// 输入：abcxyz\n, c 的值为 abc\0, 缓冲区中的数据为 xyz\n
	// 输入：abcdefghijklmnopqrstuvwxyz\n, c 的值为 abcdefghi\0, 缓冲区中的数据为 jklmnopqrstuvwxyz\n


	// cin.getline()
	// 其用法同 cin.get(), 但是 cin.getline() 会自动清除缓冲区中的'\n'


	// 注意：每次 cin.get()/cin.getline() 的时候，之前的缓冲区中的数据也仍然有效，可以通过如下方法清除输入缓冲区
	// std::cin.sync();
}



// cerr, clog
void cppio1_demo4()
{
	// cout, cerr, clog 都是类型 ostream 的对象
	// cerr 是标准错误流，只能输出到显示器。而 cout 除了输出到显示器之外，也可以被重定向输出到磁盘文件等地方
	// clog 同 cerr，区别是 cerr 不经过缓冲区，而 clog 需要经过缓冲区（cout 也要经过缓冲区）

	std::cerr << "abc";
	std::clog << "abc" << std::endl;
}



// cin.ignore(), cin.putback()
void cppio1_demo5()
{
	char c[100];
	// 跳过输入流中前 n 个字符，或在遇到指定的终止字符时提前结束（此种场景终止字符也会被跳过）
	std::cin.ignore(3, 'x');
	std::cin >> c;
	// 输入 abcdefg，则 c 值为 defg\0
	// 输入 axmn，则 c 值为 mn\0


	char c1;
	char c2[10];
	cin >> c1;
	cin.putback('a'); // 在 cin 缓冲区的当前指针处插入指定的字符，然后指针往前移一个字符
	cin.putback('b');
	cin.putback(c1);
	cin >> c2;
	// 输入 x，则 c1 的值为 x，c2 的值为 xba\0
}



// 在 linux 系统中，一切设备都看作文件。而每打开一个文件，就有一个代表该打开文件的文件描述符（file descriptor）
// 程序启动时，默认打开三个 I/O 设备文件：标准输入文件（stdin），标准输出文件（stdout），标准错误输出文件（stderr），其对应的文件描述符分别为 0, 1, 2