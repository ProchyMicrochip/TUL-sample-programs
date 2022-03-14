using System;
using System.Drawing;
using System.Timers;
using System.Windows.Forms;
using System.Windows;

namespace Programovani.VisualMovement
{
    public partial class Form1 : Form
    {
        struct MovementVector
        {
            public double Right;
            public double Down;

            public MovementVector(double i, double i1)
            {
                Right = i;
                Down = i1;
            }
        }

        private MovementVector _movementVector;

        public Form1()
        {
            
            InitializeComponent();
            button1.Location = new Point((Size.Width - button1.Width) / 2, (Size.Height - button1.Height) / 2);
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            var mouse = (MouseEventArgs) e;
            var angle = Math.Atan2(mouse.X - button1.Location.X- button1.Width/2, mouse.Y - button1.Location.Y- button1.Height/2);
            _movementVector = new MovementVector(Math.Sin(angle), Math.Cos(angle));
            timer1.Enabled = !timer1.Enabled;
            if(!timer1.Enabled) button1.Location = new Point((Size.Width - button1.Width) / 2, (Size.Height - button1.Height) / 2);
        }

        private void CheckBoundingBox()
        {
            if (button1.Location.X <= 0 || button1.Location.X + button1.Width >= Size.Width)
                _movementVector = new MovementVector(-_movementVector.Right, _movementVector.Down);
            if (button1.Location.Y <= 0 || button1.Location.Y + button1.Height*2 +20 >= Size.Height)
                _movementVector = new MovementVector(_movementVector.Right, -_movementVector.Down);
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            button1.Location = new Point((Size.Width - button1.Width) / 2, (Size.Height - button1.Height) / 2);
        }

        private void timer1_Elapsed(object sender, ElapsedEventArgs e)
        {
            CheckBoundingBox();
            button1.Location = new Point((int) (button1.Location.X + _movementVector.Right * 10),
                (int) (button1.Location.Y + _movementVector.Down * 10));
        }
    }
}