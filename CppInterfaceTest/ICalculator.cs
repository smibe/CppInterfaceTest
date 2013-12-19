using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CppInterfaceTest
{
    [Guid("F3C4F98C-BBDC-4B2E-B67A-12E1475109FE")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface ICalculator : IDisposable
    {
        [PreserveSig]
        int Add(int op1, int op2);
    }
}
