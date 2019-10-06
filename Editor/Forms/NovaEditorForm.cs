using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Editor
{
    public partial class frmNovaEditor : Form
    {
        [DllImportAttribute("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd,
            int Msg, int wParam, int lParam);
        [DllImportAttribute("user32.dll")]
        public static extern bool ReleaseCapture();

        private bool _consoleOutputActivated = true;

        public frmNovaEditor()
        {
            InitializeComponent();
            SetStyle(ControlStyles.ResizeRedraw, true);

            update_title_bar_location();
        }

        public IntPtr GetGameHandleRef()
        {
            return pnlGame.Handle;
        }

        private void update_title_bar_location()
        {
            var textWidth = lbWindowTitle.Width;
            var titleWidth = Width;

            var location = lbWindowTitle.Location;
            location.X = (int) (titleWidth - (0.5 * textWidth));
        }

        private void btnCloseWindow_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnMaximizeWindow_Click(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Maximized)
            {
                WindowState = FormWindowState.Normal;
                btnMaximizeWindow.BackgroundImage = Properties.Resources.window_restore_32;
            }
            else
            {
                WindowState = FormWindowState.Maximized;
                btnMaximizeWindow.BackgroundImage = Properties.Resources.window_maximize_32;
            }
        }

        private void btnMinimize_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }

        private void pnlTitle_MouseDown(object sender, MouseEventArgs e)
        {
        const int WM_NCLBUTTONDOWN = 0xA1;
        const int HT_CAPTION = 0x2;

        if (e.Button == MouseButtons.Left)
        {
            ReleaseCapture();
            SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
        }
        }
    }
}
