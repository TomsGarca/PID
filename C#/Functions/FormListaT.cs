using MySql.Data.MySqlClient;
namespace Interfaz
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void Form6_Load(object sender, EventArgs e)
        {
            connect();
        }

        private void connect()
        {
            MySqlConnection conn;
            string server = "localhost";
            string database = "pid";
            string user = "root";
            string password = "12346578a";
            string port = "3306";
            string sslM = "none";

            string connString = String.Format("server={0};port={1};user id={2}; password={3}; database={4}; SslMode={5}", server, port, user, password, database, sslM);

            conn = new MySqlConnection(connString);
            try
            {
                conn.Open();

                this.label1_1.BackColor = Color.Green;
                Console.WriteLine("Connection Successful");

                conn.Close();
            }
            catch (MySqlException e)
            {
                Console.WriteLine(e.Message + connString);
            }
        }

    }
}