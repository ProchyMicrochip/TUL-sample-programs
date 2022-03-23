using System.ComponentModel;
using System.Windows.Forms;

namespace Programovani.Dictionary
{
    public partial class Form1 : Form
    {
        private readonly CustomList _customList = new CustomList();
        public Form1()
        {
            InitializeComponent();
            dataGridView1.AutoGenerateColumns = true;
            dataGridView1.DataSource = _customList.List;
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            _customList.Add(new CustomPoint(e.X,e.Y, textBox1.Text));
           dataGridView1.Update();
        }
    }
}