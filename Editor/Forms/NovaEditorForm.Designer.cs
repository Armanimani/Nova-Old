namespace Editor
{
    partial class frmNovaEditor
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmNovaEditor));
            this.pnlTitle = new System.Windows.Forms.Panel();
            this.lbWindowTitle = new System.Windows.Forms.Label();
            this.pnlTitleName = new System.Windows.Forms.Panel();
            this.pnlLogo = new System.Windows.Forms.Panel();
            this.btnLogo = new System.Windows.Forms.Button();
            this.pnlWindowControl = new System.Windows.Forms.Panel();
            this.btnMinimize = new System.Windows.Forms.Button();
            this.btnMaximizeWindow = new System.Windows.Forms.Button();
            this.btnCloseWindow = new System.Windows.Forms.Button();
            this.pnlDragable = new System.Windows.Forms.Panel();
            this.pnlTitle.SuspendLayout();
            this.pnlLogo.SuspendLayout();
            this.pnlWindowControl.SuspendLayout();
            this.pnlDragable.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlTitle
            // 
            this.pnlTitle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.pnlTitle.Controls.Add(this.lbWindowTitle);
            this.pnlTitle.Controls.Add(this.pnlTitleName);
            this.pnlTitle.Controls.Add(this.pnlLogo);
            this.pnlTitle.Controls.Add(this.pnlWindowControl);
            this.pnlTitle.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTitle.Location = new System.Drawing.Point(0, 0);
            this.pnlTitle.Name = "pnlTitle";
            this.pnlTitle.Size = new System.Drawing.Size(1920, 32);
            this.pnlTitle.TabIndex = 0;
            this.pnlTitle.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pnlTitle_MouseDown);
            // 
            // lbWindowTitle
            // 
            this.lbWindowTitle.AutoSize = true;
            this.lbWindowTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbWindowTitle.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(240)))), ((int)(((byte)(240)))));
            this.lbWindowTitle.Location = new System.Drawing.Point(905, 8);
            this.lbWindowTitle.Name = "lbWindowTitle";
            this.lbWindowTitle.Size = new System.Drawing.Size(83, 17);
            this.lbWindowTitle.TabIndex = 0;
            this.lbWindowTitle.Text = "Nova-Editor";
            // 
            // pnlTitleName
            // 
            this.pnlTitleName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pnlTitleName.AutoSize = true;
            this.pnlTitleName.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.pnlTitleName.Location = new System.Drawing.Point(960, 0);
            this.pnlTitleName.Margin = new System.Windows.Forms.Padding(0);
            this.pnlTitleName.Name = "pnlTitleName";
            this.pnlTitleName.Size = new System.Drawing.Size(0, 0);
            this.pnlTitleName.TabIndex = 1;
            // 
            // pnlLogo
            // 
            this.pnlLogo.AutoSize = true;
            this.pnlLogo.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.pnlLogo.Controls.Add(this.btnLogo);
            this.pnlLogo.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLogo.Location = new System.Drawing.Point(0, 0);
            this.pnlLogo.Name = "pnlLogo";
            this.pnlLogo.Size = new System.Drawing.Size(32, 32);
            this.pnlLogo.TabIndex = 1;
            // 
            // btnLogo
            // 
            this.btnLogo.AutoSize = true;
            this.btnLogo.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.btnLogo.BackgroundImage = global::Editor.Properties.Resources.nova_logo_white_32;
            this.btnLogo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnLogo.Dock = System.Windows.Forms.DockStyle.Left;
            this.btnLogo.FlatAppearance.BorderSize = 0;
            this.btnLogo.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DodgerBlue;
            this.btnLogo.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.btnLogo.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnLogo.Location = new System.Drawing.Point(0, 0);
            this.btnLogo.Margin = new System.Windows.Forms.Padding(0);
            this.btnLogo.Name = "btnLogo";
            this.btnLogo.Size = new System.Drawing.Size(32, 32);
            this.btnLogo.TabIndex = 4;
            this.btnLogo.UseVisualStyleBackColor = false;
            // 
            // pnlWindowControl
            // 
            this.pnlWindowControl.AutoSize = true;
            this.pnlWindowControl.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.pnlWindowControl.Controls.Add(this.btnMinimize);
            this.pnlWindowControl.Controls.Add(this.btnMaximizeWindow);
            this.pnlWindowControl.Controls.Add(this.btnCloseWindow);
            this.pnlWindowControl.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlWindowControl.Location = new System.Drawing.Point(1800, 0);
            this.pnlWindowControl.Name = "pnlWindowControl";
            this.pnlWindowControl.Size = new System.Drawing.Size(120, 32);
            this.pnlWindowControl.TabIndex = 1;
            // 
            // btnMinimize
            // 
            this.btnMinimize.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.btnMinimize.BackgroundImage = global::Editor.Properties.Resources.window_minimize_32;
            this.btnMinimize.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnMinimize.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnMinimize.FlatAppearance.BorderSize = 0;
            this.btnMinimize.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DodgerBlue;
            this.btnMinimize.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.btnMinimize.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMinimize.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(240)))), ((int)(((byte)(240)))));
            this.btnMinimize.Location = new System.Drawing.Point(0, 0);
            this.btnMinimize.Margin = new System.Windows.Forms.Padding(0);
            this.btnMinimize.Name = "btnMinimize";
            this.btnMinimize.Size = new System.Drawing.Size(40, 32);
            this.btnMinimize.TabIndex = 3;
            this.btnMinimize.UseVisualStyleBackColor = false;
            this.btnMinimize.Click += new System.EventHandler(this.btnMinimize_Click);
            // 
            // btnMaximizeWindow
            // 
            this.btnMaximizeWindow.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.btnMaximizeWindow.BackgroundImage = global::Editor.Properties.Resources.window_maximize_32;
            this.btnMaximizeWindow.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnMaximizeWindow.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnMaximizeWindow.FlatAppearance.BorderSize = 0;
            this.btnMaximizeWindow.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DodgerBlue;
            this.btnMaximizeWindow.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.btnMaximizeWindow.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMaximizeWindow.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(240)))), ((int)(((byte)(240)))));
            this.btnMaximizeWindow.Location = new System.Drawing.Point(40, 0);
            this.btnMaximizeWindow.Margin = new System.Windows.Forms.Padding(0);
            this.btnMaximizeWindow.Name = "btnMaximizeWindow";
            this.btnMaximizeWindow.Size = new System.Drawing.Size(40, 32);
            this.btnMaximizeWindow.TabIndex = 2;
            this.btnMaximizeWindow.UseVisualStyleBackColor = false;
            this.btnMaximizeWindow.Click += new System.EventHandler(this.btnMaximizeWindow_Click);
            // 
            // btnCloseWindow
            // 
            this.btnCloseWindow.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.btnCloseWindow.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnCloseWindow.BackgroundImage")));
            this.btnCloseWindow.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnCloseWindow.Dock = System.Windows.Forms.DockStyle.Right;
            this.btnCloseWindow.FlatAppearance.BorderSize = 0;
            this.btnCloseWindow.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DodgerBlue;
            this.btnCloseWindow.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            this.btnCloseWindow.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnCloseWindow.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(240)))), ((int)(((byte)(240)))));
            this.btnCloseWindow.Location = new System.Drawing.Point(80, 0);
            this.btnCloseWindow.Margin = new System.Windows.Forms.Padding(0);
            this.btnCloseWindow.Name = "btnCloseWindow";
            this.btnCloseWindow.Size = new System.Drawing.Size(40, 32);
            this.btnCloseWindow.TabIndex = 1;
            this.btnCloseWindow.UseVisualStyleBackColor = false;
            this.btnCloseWindow.Click += new System.EventHandler(this.btnCloseWindow_Click);
            // 
            // pnlDragable
            // 
            this.pnlDragable.Controls.Add(this.pnlTitle);
            this.pnlDragable.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlDragable.Location = new System.Drawing.Point(0, 0);
            this.pnlDragable.Name = "pnlDragable";
            this.pnlDragable.Size = new System.Drawing.Size(1920, 32);
            this.pnlDragable.TabIndex = 1;
            // 
            // frmNovaEditor
            // 
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.ClientSize = new System.Drawing.Size(1920, 1080);
            this.Controls.Add(this.pnlDragable);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "frmNovaEditor";
            this.pnlTitle.ResumeLayout(false);
            this.pnlTitle.PerformLayout();
            this.pnlLogo.ResumeLayout(false);
            this.pnlLogo.PerformLayout();
            this.pnlWindowControl.ResumeLayout(false);
            this.pnlDragable.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlTitle;
        private System.Windows.Forms.Button btnMaximizeWindow;
        private System.Windows.Forms.Button btnCloseWindow;
        private System.Windows.Forms.Button btnMinimize;
        private System.Windows.Forms.Button btnLogo;
        private System.Windows.Forms.Panel pnlWindowControl;
        private System.Windows.Forms.Panel pnlLogo;
        private System.Windows.Forms.Panel pnlTitleName;
        private System.Windows.Forms.Label lbWindowTitle;
        private System.Windows.Forms.Panel pnlDragable;
    }
}

