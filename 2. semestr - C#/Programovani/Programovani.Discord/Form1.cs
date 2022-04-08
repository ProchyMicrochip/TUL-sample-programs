using System;
using System.ComponentModel;
using System.Windows.Forms;
using Programovani.VisualMovement;

//implementujte třídy (odvozené od bázové třídy) pro jednotlivé typy pamětí LIFO, FIFO a kruhový buffer



namespace Programovani.Discord
{
    public partial class Form1 : Form
    {
        private Base _base;
        public Form1()
        {
            InitializeComponent();
            Pamet.SelectedIndex = 0;
            dataGridView1.AutoGenerateColumns = true;
        }
//Zapis
        private void button2_Click(object sender, EventArgs e)
        {
            _base.Write(new MyClass(){Animal = textBox1.Text , Name = textBox2.Text,Age = (int)numericUpDown1.Value});
            UpdateData();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MyClass myClass = _base.Read();
            textBox4.Text = myClass.Animal;
            textBox3.Text = myClass.Name;
            numericUpDown2.Value = myClass.Age;
            UpdateData();
        }

        private void Pamet_SelectedIndexChanged(object sender, EventArgs e)
        {
            ComboBox comboBox = (ComboBox)sender;
            switch (comboBox.SelectedIndex)
            {
                case 0:
                    _base = new Fifo(10);
                    break;
                case 1:
                    _base = new Lifo(10);
                    break;
                case 2:
                    _base = new Buffer(10);
                    break;
            }
        }

        private void UpdateData()
        {
            BindingList<MyClass> bindingList = new BindingList<MyClass>(_base.pole);
            dataGridView1.DataSource = bindingList;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            _base.Reset();
        }
    }
}