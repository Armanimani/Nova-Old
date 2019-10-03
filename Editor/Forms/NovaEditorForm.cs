using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Editor
{
    public partial class frmNovaEditor : Form
    {
        public frmNovaEditor()
        {
            InitializeComponent();
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
    }
}
