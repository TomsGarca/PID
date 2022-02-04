namespace Interfaz
{
    partial class Form3
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
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.comboBox3 = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();

            this.label1.Location = new System.Drawing.Point(15,19);
            this.label1.Name = "Procesador";
            this.label1.AutoSize = true;
            this.label1.Text = "Tipo de Procesador:";

            this.comboBox1.Location = new System.Drawing.Point(140, 15);
            this.comboBox1.Name = "TipoProcesador";
            this.comboBox1.Size = new System.Drawing.Size(120, 25);
            this.comboBox1.Items.Add("Mono-Proceso");
            this.comboBox1.Items.Add("Multi-Proceso");
            this.comboBox1.SelectedValueChanged += new EventHandler(this.comboBox1_SelectItem);
            
            this.label2.Location = new System.Drawing.Point(15,49);
            this.label2.Name = "Canal";
            this.label2.AutoSize = true;
            this.label2.Text = "Numero de Canales:";

            this.comboBox2.Location = new System.Drawing.Point(140, 45);
            this.comboBox2.Name = "NCanales";
            this.comboBox2.Size = new System.Drawing.Size(120, 25);

            this.label3.Location = new System.Drawing.Point(15,79);
            this.label3.Name = "Gestion";
            this.label3.AutoSize = true;
            this.label3.Text = "Tipo de Gestion:";

            this.comboBox3.Location = new System.Drawing.Point(140, 75);
            this.comboBox3.Name = "TipoGestion";
            this.comboBox3.Size = new System.Drawing.Size(120, 25);
            this.comboBox3.Items.Add("Mono-Tarea");
            this.comboBox3.Items.Add("Multi-Tarea");

            this.button1.Location = new System.Drawing.Point(100, 120);
            this.button1.Name = "Guardar";
            this.button1.Size = new System.Drawing.Size(85, 25);
            this.button1.Text = "Guardar";
            this.button1.Click += new EventHandler(this.button1_Guardar);

            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(285, 170);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comboBox2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.comboBox3);
            this.Controls.Add(this.button1);
            this.Name = "ModProcesador";
            this.Text = "Modificar Procesador";
        }
        
        private Label label1;
        private ComboBox comboBox1;
        private Label label2;
        private ComboBox comboBox2;
        private Label label3;
        private ComboBox comboBox3;
        private Button button1;

    }
}