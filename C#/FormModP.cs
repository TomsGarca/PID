namespace Interfaz
{
    partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }
        private void comboBox1_SelectItem(object sender, EventArgs e)
        {
            if (this.comboBox1.Text == "Mono-Proceso")
            {
                this.comboBox2.Items.Clear();
                this.comboBox2.Items.AddRange(new object[] {"1"});
                
            }
            else if ( this.comboBox1.Text == "Multi-Proceso")
            {
                this.comboBox2.Items.Clear();
                this.comboBox2.Items.AddRange(new object[] {"1","2", "3", "4", "5", "6", "7", "8", "9", "10"});
                this.comboBox2.DropDownHeight = 75;
            }
        }
        private void button1_Guardar(object sender, EventArgs e)
        {
            MessageBox.Show("Procesador modificado exitosamente :3");
            this.Close();
        }
    }
}