
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
            this.button1 = new System.Windows.Forms.Button();


            this.label1.Location =  new System.Drawing.Point(15, 20);
            this.label1.Name = "connection";
            this.label1.Text = "Connection:";
            this.label1.AutoSize = true;
            
            this.label1_1.Location = new System.Drawing.Point(165, 20);
            this.label1_1.Name = "status";
            this.label1_1.Text = "Desconectado";
            this.label1_1.BackColor = Color.Red;
            this.label1_1.Size = new System.Drawing.Size(165, 40);

            this.button1.Location = new System.Drawing.Point(60, 75);
            this.button1.Name = "close";
            this.button1.Text = "Close Connection";
            this.button1.AutoSize = true;
            this.button1.Click += new EventHandler(this.button1_close);

            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(350, 150);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label1_1);
            this.Name = "ListaTareas";
            this.Text = "Lista de Tareas";
            this.Load += new System.EventHandler(this.Form6_Load);
        }

        private Label label1;
        private Label label1_1;
        private Button button1;
    }
}