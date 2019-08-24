using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace RockLoader
{
    class Program
    {
        static void Main(string[] args)
        {
            WL("开始释放 StudentRock");
            ReleaseDepFile();
            WL("");
            WL("Done.");
            WL("你可以运行当前目录下的 StudentRock 来启动主程序。");
            WL("按任意键退出");
            Console.ReadKey();
        }
        static void ReleaseDepFile()
        {
            File.WriteAllBytes("LibStHook.dll", Properties.Resources.LIBSTHOOK);
            W(".");
            File.WriteAllBytes("MinHook.x86.dll", Properties.Resources.MinHook_x86);
            W(".");
            File.WriteAllBytes("SimpleUpdater.dll", Properties.Resources.SimpleUpdater);
            W(".");
            File.WriteAllBytes("StudentRock.exe", Properties.Resources.StudentRock);
            W(".");
        }
        static void WL(string msg, params object[] args)
        {
            Console.WriteLine(msg, args);
        }
        static void W(string msg, params object[] args)
        {
            Console.Write(msg, args);
        }
    }
}
