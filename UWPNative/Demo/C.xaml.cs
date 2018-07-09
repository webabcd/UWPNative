using System;
using System.Reflection;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace UWPNative.Demo
{
    public sealed partial class C : Page
    {
        public C()
        {
            this.InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            string param = e.Parameter.ToString();

            string result = "";
            if (param == "FileDemo")
            {
                string rootPath = Windows.Storage.ApplicationData.Current.LocalFolder.Path;
                NativeDll.DemoC demoC = new NativeDll.DemoC();
                result = demoC.FileDemo(rootPath);
            }
            else
            {
                NativeDll.DemoC demoC = new NativeDll.DemoC();
                MethodInfo mi = demoC.GetType().GetRuntimeMethod(param, new Type[] { });
                object returnValue = mi.Invoke(demoC, null);
                result = returnValue.ToString();
            }

            lblMsg.Text = result.ToString();
        }
    }
}
