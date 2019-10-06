using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace Editor
{
    class EngineWrapper
    {
        [DllImport("Editor-Binding.dll")]
        public static extern void start_editor_application();
    }
}
