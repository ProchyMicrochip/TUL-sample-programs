using System;
using System.Globalization;
using System.Windows.Forms;

namespace Programovani.Consumption
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        private void button1_Click_1(object sender, EventArgs e)
        {
            textBox1.Text = double.TryParse(textBox2.Text,out var zaklad) ? Library.Library.GetConsumption(dateTimePicker1.Value, dateTimePicker2.Value, zaklad, checkBox2.Checked, checkBox1.Checked).ToString(CultureInfo.InvariantCulture)+" kWh" : "neplatny zaklad";
        }
    }
}