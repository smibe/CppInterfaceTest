using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using CppInterfaceTest;

namespace CalculatorConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            using (CppInterface<ICalculator> calculatorWrapper = CppInstanceFactory<ICalculator>.CreateInstance())
            {
                ICalculator calculator = calculatorWrapper.Object;
                Console.WriteLine("1 + 4 = {0}", calculator.Add(1, 4));
                Console.WriteLine("calculator.GetText:", calculator.GetText(1, 4));
            }
        }
    }
}
