using System;
using Programovani.VisualMovement;

namespace Programovani.Discord
{
    public class Fifo: Base
    {
        public Fifo(int size) : base(size)
        {
        }

        public override void Write(MyClass myClass)
        {
            if (Count >= pole.Length) throw new BufferIsFull();
            pole[Count++] = myClass;
        }

        public override MyClass Read()
        {
            if (Count == 0) throw new NothingToRead();
            MyClass myClass = pole[0];
            for (int i = 1; i < pole.Length; i++)
            {
                pole[i - 1] = pole[i];
            }
            Count--;
            return myClass;
        }

        public override void Reset()
        {
            Count = 0;
            SeletedIndex = 0;
            Array.Clear(pole,0,pole.Length-1);
        }
    }
}