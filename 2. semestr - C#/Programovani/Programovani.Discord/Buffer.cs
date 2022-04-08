using System;
using Programovani.VisualMovement;

namespace Programovani.Discord
{
    public class Buffer : Base
    {
        public Buffer(int size) : base(size)
        {
        }

        public override void Write(MyClass myClass)
        {
            if (Count >= pole.Length) throw new BufferIsFull();
            pole[Count++] = myClass;
        }

        public override MyClass Read()
        {
            MyClass myClass = pole[SeletedIndex++];
            if (Count == 0) throw new NothingToRead();
            SeletedIndex %= Count;
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