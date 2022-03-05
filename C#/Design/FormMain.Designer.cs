namespace Interfaz
{

    partial class Form1
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

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button2_1 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();

            this.label1.Location = new System.Drawing.Point(93, 20);
            this.label1.Name = "label1";
            this.label1.AutoSize = true;
            this.label1.Text = "Simulación de Procesador";

            this.label2.Location = new System.Drawing.Point(125, 40);
            this.label2.Name = "label2";
            this.label2.AutoSize = true;
            this.label2.Text = "¡BIENVENIDO!";

            this.button1.Location = new System.Drawing.Point(15, 70);
            this.button1.Name = "NuevaTarea";
            this.button1.Size = new System.Drawing.Size(300, 25);
            this.button1.Text = "Nueva Tarea";
            this.button1.Click += new EventHandler(this.button1_Click_1);

            this.button2.Location = new System.Drawing.Point(215, 100);
            this.button2.Name = "ElegirArchivo";
            this.button2.Size = new System.Drawing.Size(100, 25);
            this.button2.Text = "Elegir Archivo";
            this.button2.Click += new EventHandler(this.button2_Abrir_Archivo);

            this.button2_1.Location = new System.Drawing.Point(15, 130);
            this.button2_1.Name = "AddTareaArch";
            this.button2_1.Size = new System.Drawing.Size(300, 25);
            this.button2_1.Text = "Agregar Tarea desde Archivo";
            this.button2_1.Click += new EventHandler(this.button2_Agregar_Tarea);

            this.button3.Location = new System.Drawing.Point(15, 160);
            this.button3.Name = "ListTarea";
            this.button3.Size = new System.Drawing.Size(300, 25);
            this.button3.Text = "Lista de Tareas";
            this.button3.Click += new EventHandler(this.button3_Click_1);

            this.button4.Location = new System.Drawing.Point(15, 190);
            this.button4.Name = "ModProcesador";
            this.button4.Size = new System.Drawing.Size(300, 25);
            this.button4.Text = "Modificar Procesador";
            this.button4.Click += new EventHandler(this.button4_Click_1);

            this.button5.Location = new System.Drawing.Point(15, 220);
            this.button5.Name = "Iniciar";
            this.button5.Size = new System.Drawing.Size(300, 25);
            this.button5.Text = "Iniciar";
            this.button5.Click += new EventHandler(this.button5_Click_1);

            this.button6.Location = new System.Drawing.Point(15, 250);
            this.button6.Name = "Eliminar";
            this.button6.Size = new System.Drawing.Size(300, 25);
            this.button6.Text = "Eliminar";
            this.button6.Click += new EventHandler(this.button6_Click_1);

            this.textBox1.Location = new System.Drawing.Point(15, 100);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(195, 25);
            this.textBox1.Text = "C:\\";

            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(340, 350);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button2_1);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox1);
            this.Name = "Menu";
            this.Text = "PROYECTO PID";
        }

        #endregion
        private Button button1;
        private Button button2;
        private Button button2_1;
        private Button button3;
        private Button button4;
        private Button button5;
        private Button button6;

        private Label label1;
        private Label label2;
        private TextBox textBox1;
        private OpenFileDialog openFileDialog1;
    }
}