using System;
using System.IO;
using System.Security;
using System.Windows.Forms;
namespace Interfaz
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            Form emergeNT = new Form2();
            emergeNT.ShowDialog();
        }
        private void setText(string text)
        {
            textBox1.Text = text;
        }
        private void button2_Abrir_Archivo(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    string sr = openFileDialog1.FileName;
                    setText(sr);
                }
                catch (SecurityException ex)
                {
                    MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }
        }
        private void button2_Agregar_Tarea(object sender, EventArgs e)
        {
            MessageBox.Show("Tarea agregada exitosamente :3");
            textBox1.Text = " ";
        }
        private void button3_Click_1(object sender, EventArgs e)
        {

        }
        private void button4_Click_1(object sender, EventArgs e)
        {
            Form emergenteMP = new Form3();
            emergenteMP.ShowDialog();
        }
        private void button5_Click_1(object sender, EventArgs e)
        {

        }
        private void button6_Click_1(object sender, EventArgs e)
        {

        }
    }
}