using System;
using System.Reflection;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace UWPNative.Demo
{
    public sealed partial class Cpp : Page
    {
        public Cpp()
        {
            this.InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            string param = e.Parameter.ToString();

            string result = "";
            if (param == "HelloDemo")
            {
                NativeDll.DemoCpp demoCpp = new NativeDll.DemoCpp();
                result = demoCpp.HelloDemo("王磊");
            }
            else if (param == "IO2Demo") // 文件 demo
            {
                string rootPath = Windows.Storage.ApplicationData.Current.LocalFolder.Path;
                NativeDll.DemoCpp demoCpp = new NativeDll.DemoCpp();
                result = demoCpp.IO2Demo(rootPath);
            }
            else
            {
                NativeDll.DemoCpp demoCpp = new NativeDll.DemoCpp();
                MethodInfo mi = demoCpp.GetType().GetRuntimeMethod(param, new Type[] { });
                object returnValue = mi.Invoke(demoCpp, null);
                result = returnValue.ToString();
            }

            lblMsg.Text = result.ToString();
        }
    }
}
