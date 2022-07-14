using MySql.Data.MySqlClient;
namespace Interfaz
{
    public partial class Form6 : Form
    {
        MySqlConnection conn;
        public Form6()
        {
            InitializeComponent();
        }

        private void Form6_Load(object sender, EventArgs e)
        {
            connect();
            if (true)
            {
                
            }
        }

        private void connect()
        {
            // MySqlConnection conn;
            string server = "localhost";
            string database = "pid";
            string user = "root";
            string password = "12345678a";
            //string password = "";
            string port = "3306";
            string sslM = "none";

            string connString = String.Format("server={0};port={1};user id={2}; password={3}; database={4}; SslMode={5}", server, port, user, password, database, sslM);

            conn = new MySqlConnection(connString);
            try
            {
                conn.Open();

                this.label1_1.Text = "Conectado";
                this.label1_1.BackColor = Color.Green;
                this.label1_1.Size = new System.Drawing.Size(130, 40);

                this.Controls.Add(this.button1);
                
            }
            catch (MySqlException e)
            {
                Console.WriteLine(e.Message + connString);
            }
        }
        
        private void button1_close(Object sender, EventArgs e)
        {
            conn.Close();

            this.label1_1.Text = "Desconectado";
            this.label1_1.BackColor = Color.Red;
            this.label1_1.Size = new System.Drawing.Size(165, 40);
        }
    }
}