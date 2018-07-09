/*
 * 演示 C#, C++/CX, C/C++ 间的通信
 *
 * 本例创建了一个接口，暴露给 C# 去实现，C# 实现此接口后，C++/CX 就可以通过此接口中的方法发送数据给 C#
 */

#pragma once 

namespace NativeDll
{
	public interface class ICallback
	{
		void Cx2Cs(Platform::String^ message);
	};
}