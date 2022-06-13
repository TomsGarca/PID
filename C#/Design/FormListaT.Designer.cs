
namespace Interfaz
{
    partial class Form6 : Form
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

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.label1_1 = new System.Windows.Forms.Label();


            this.label1.Location =  new System.Drawing.Point(15, 10);
            this.label1.Name = "connection";
            this.label1.Text = "Connection:";
            this.label1.AutoSize = true;
            
            this.label1_1.Location = new System.Drawing.Point(110, 10);
            this.label1_1.Name = "status";
            this.label1_1.BackColor = Color.Red;
            this.label1_1.Size = new System.Drawing.Size(40, 20);

            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(300, 260);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label1_1);
            this.Name = "ListaTareas";
            this.Text = "Lista de Tareas";
            this.Load += new System.EventHandler(this.Form6_Load);
        }

        private Label label1;
        private Label label1_1;
    }
}