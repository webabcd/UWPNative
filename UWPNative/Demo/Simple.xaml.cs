/*
 * 演示如何用 C# 调用 C++
 * 
 * 对应的 Windows Runtime Component(C++) 详见 NativeDll 项目
 * 注意：Windows Runtime Component 项目会生成 .winmd 文件，winmd - Windows Metadata，其是语言无关的
 */

using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace UWPNative.Demo
{
    public sealed partial class Simple : Page
    {
        public Simple()
        {
            this.InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            // 调用 C++ 中的函数
            NativeDll.Simple simple = new NativeDll.Simple();
            int result = simple.Add(1, 1);

            lblMsg.Text = "1 + 1 = " + result.ToString();
        }
    }
}
