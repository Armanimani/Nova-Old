using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Editor
{
    static class Program
    {
        [MTAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            
            frmNovaEditor form = new frmNovaEditor();

            new Thread(() =>
            {
                Thread.CurrentThread.IsBackground = true;
                EngineWrapper.start_editor_application();
            }).Start();

            Application.Run(form);
        }
    }
}
