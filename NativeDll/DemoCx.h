#pragma once 

#include "ICallback.h"

using namespace Platform;

namespace NativeDll 
{
	// ref class 可被输出到元数据（winmd - Windows Metadata），以便其他托管程序调用
	public ref class DemoCx sealed 
	{
	public:
		// 用“^”标记的，系统会负责他们的引用计数，当引用计数为 0 时，它们会被销毁
		String^ HelloCx(String^ name); 

		String^ HelloCpp(String^ name);


		// 由 C# 调用，用于设置 ICallback 对象
		void SetCallback(ICallback^ callback);

		// 由 C++/CX 调用，用于通过 ICallback 向 C# 发送数据
		property static ICallback^ GlobalCallback;
	};
}