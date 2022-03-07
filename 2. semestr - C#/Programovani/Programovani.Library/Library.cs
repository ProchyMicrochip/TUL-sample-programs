using System;
using System.Collections.Generic;
using System.Linq;

namespace Programovani.Library
{

    public class Library
    {
        private static readonly Dictionary<DayOfWeek, double> Vazeni = new Dictionary<DayOfWeek, double>()
        {
            {DayOfWeek.Monday, 0.85}, {DayOfWeek.Tuesday, 0.90}, {DayOfWeek.Wednesday, 0.90}, {DayOfWeek.Thursday, 1.10},
            {DayOfWeek.Friday, 0.70}
        };

        private static readonly Dictionary<DayOfWeek, double> Weekend = new Dictionary<DayOfWeek, double>()
        {
            {DayOfWeek.Saturday, 1.5}, {DayOfWeek.Sunday, 1.5}
        };
        public static double GetConsumption(DateTime from, DateTime to,double zaklad, bool isWeighted, bool weekend)
        {
            var convertionChart = isWeighted ? Vazeni.ToList() : new List<KeyValuePair<DayOfWeek, double>>(); 
            if(weekend) convertionChart.AddRange(Weekend.ToList());
            var convertionDict = convertionChart.ToDictionary(x => x.Key, x=> x.Value );
            double sum = 0;
            while (from.Date <=to.Date)
            {
                double multiplier;
                multiplier = convertionDict.TryGetValue(from.DayOfWeek, out multiplier) ? multiplier : 1f;
                sum += zaklad * multiplier;
                from =from.AddDays(1);
            }
            return sum;
        }
      
        
    }
}