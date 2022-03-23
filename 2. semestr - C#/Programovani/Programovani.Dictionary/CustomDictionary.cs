using System.ComponentModel;
using System.Linq;

namespace Programovani.Dictionary
{
    public class CustomPoint
    {
        public int X { get; set; }
        public int Y{ get; set; }
        public string Name{ get; set; }

        public CustomPoint(int x, int y, string name = "auto")
        {
            if (name.Equals("")) name = "auto";
            X = x;
            Y = y;
            Name = name;
        }
    }

    public class CustomList
    {
        public BindingList<CustomPoint> List = new BindingList<CustomPoint>();

        public void Add(CustomPoint point)
        {
            if (point.Name.Equals("auto"))
            {
                point.Name += List.Count(name => name.Name.Contains("auto"));
            }

            List.Add(point);
        }

        public void RemoveAt(int index)
        {
            List.RemoveAt(index);
        }

        public void Remove(CustomPoint point)
        {
            List.Remove(point);
        }

        public void Clear()
        {
            List.Clear();
        }
        
        
    }
}