/*
 * 演示 C#, C++/CX, C/C++ 间的通信
 * 
 * 本例是 C# 部分
 * 
 * 
 * C# 与 C++/CX 间通信；C++/CX 与 C/C++ 间通信；C# 通过 C++/CX 与 C/C++ 间通信
 */

using System;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace UWPNative.Demo
{
    public sealed partial class Cx : Page
    {
        public Cx()
        {
            this.InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            NativeDll.DemoCx demoCx = new NativeDll.DemoCx();

            MyCallback myCallback = new MyCallback();
            myCallback.MessageReceived += myCallback_MessageReceived;
            demoCx.SetCallback(myCallback);

            // C# 调用 C++/CX
            lblMsg.Text += demoCx.HelloCx("cs to c++/cx");
            lblMsg.Text += Environment.NewLine;

            // C# 通过 C++/CX 调用 C/C++
            lblMsg.Text += demoCx.HelloCpp("cs to c++/cx to c/c++");
            lblMsg.Text += Environment.NewLine;
        }

        async void myCallback_MessageReceived(object sender, MessageEventArgs e)
        {
            MyCallback myCallback = (MyCallback)sender;

            await lblMsg.Dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, () =>
            {
                lblMsg.Text += e.Message;
                lblMsg.Text += Environment.NewLine;
            });
        }
    }

    // 实现 C++/CX 中的 ICallback 接口
    public class MyCallback : NativeDll.ICallback
    {
        // 收到 C++/CX 直接发送过来的数据，或者 C/C++ 通过 C++/CX 发送过来的数据
        public void Cx2Cs(string message)
        {
            OnMessageReceived(new MessageEventArgs { Message = message });
        }

        public event EventHandler<MessageEventArgs> MessageReceived;
        protected virtual void OnMessageReceived(MessageEventArgs e)
        {
            EventHandler<MessageEventArgs> handler = MessageReceived;
            if (handler != null)
                handler(this, e);
        }
    }


    public class MessageEventArgs : EventArgs
    {
        public string Message { get; set; }
    }

}
