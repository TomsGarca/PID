namespace Interfaz
{
    partial class Form4
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

            this.label1.Location = new System.Drawing.Point(20, 20);
            this.label1.Name = "labe1";
            this.label1.Text = "Ingresa PID de proceso a eliminar:";
            this.label1.AutoSize = true;

            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(250, 250);
            this.Controls.Add(this.label1);
            this.Name = "EliminarTarea";
            this.Text = "Eliminar Tarea";
        }
        
        private Label label1;
    }
}