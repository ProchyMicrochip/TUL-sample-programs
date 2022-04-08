using System;
using Programovani.VisualMovement;

namespace Programovani.Discord
{
    public class Lifo : Base
    {
        public Lifo(int size) : base(size)
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
            MyClass myClass = pole[--Count];
            pole[Count] = new MyClass();
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