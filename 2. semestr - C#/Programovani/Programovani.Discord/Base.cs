using System;
using System.Net.Sockets;
using System.Threading;
using Programovani.VisualMovement;

namespace Programovani.Discord
{
    public abstract class Base
    {
        public MyClass[] pole;
        protected int Count { get; set; }
        protected int SeletedIndex { get; set; }

        protected Base(int size)
        {
            pole = new MyClass[size];
        }

        public abstract void Write(MyClass myClass);
        public abstract MyClass Read();
        public abstract void Reset();
    }
}