1、为了使用 C 语言，需要选中相应的 .c 文件 -> 右键 -> 属性 -> c/c++ -> 高级 -> 编译为 -> 编译为 C++ 代码(/TP)
2、比如你要用 strcpy 的话，在 vs 中会警告你，要求你用 strcpy_s，但是 strcpy_s 是微软自己的，为了去掉这个警告可以这么做：
  a) 在文件开头定义  #define _CRT_SECURE_NO_WARNINGS
  b) 或者一劳永逸的方法：dll 项目 -> 右键 -> 属性 -> c/c++ -> 预处理器 -> 在“预处理器定义”增加 “_CRT_SECURE_NO_WARNINGS”
3、调试本地代码：选中解决方案 -> 右键 -> 属性 -> 调试 -> 调试器类型 -> 选中“混合(托管和本机)”
4、如何在新建 c 代码时，默认保存为 utf-8 格式：在类似 D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcprojectitems 的目录下修改模板文件“hfile.h”和“newc++file.cpp”的文件格式为 utf-8