namespace Interfaz
{
    partial class Form2
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();

            this.label1.Location = new System.Drawing.Point(15,20);
            this.label1.Name = "label1";
            this.label1.Text = "Nombre:";
            this.label1.AutoSize = true;

            this.textBox1.Location = new System.Drawing.Point(100, 16);
            this.textBox1.Name = "NameProcess";
            this.textBox1.Size = new System.Drawing.Size(160,25);

            this.label2.Location = new System.Drawing.Point(15,60);
            this.label2.Name = "label2";
            this.label2.Text = "Prioridad:";
            this.label2.AutoSize = true;

            this.textBox2.Location = new System.Drawing.Point(100, 56);
            this.textBox2.Name = "PrioProcess";
            this.textBox2.Size = new System.Drawing.Size(160,25);

            this.label3.Location = new System.Drawing.Point(15,100);
            this.label3.Name = "label3";
            this.label3.Text = "T. Exe:";
            this.label3.AutoSize = true;

            this.textBox3.Location = new System.Drawing.Point(100, 96);
            this.textBox3.Name = "ExeProcess";
            this.textBox3.Size = new System.Drawing.Size(160,25);

            this.label4.Location = new System.Drawing.Point(15,140);
            this.label4.Name = "label4";
            this.label4.Text = "E. Llegada:";
            this.label4.AutoSize = true;

            this.textBox4.Location = new System.Drawing.Point(100, 136);
            this.textBox4.Name = "ArriveProcess";
            this.textBox4.Size = new System.Drawing.Size(160,25);

            this.button1.Location = new System.Drawing.Point(95, 190);
            this.Name = "AddTarea";
            this.button1.Text = "Agregar";
            this.button1.Size = new System.Drawing.Size(90, 25);
            this.button1.Click += new EventHandler(this.button1_Agregar);

            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(280, 240);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.button1);
            this.Name = "AgregarTarea";
            this.Text = "Agregar nueva tarea";
        }

        private Label label1;
        private TextBox textBox1;
        private Label label2;
        private TextBox textBox2;
        private Label label3;
        private TextBox textBox3;
        private Label label4;
        private TextBox textBox4;
        private Button button1;
    }
}