using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CppInterfaceTest
{
    public class CppInstanceFactory
    {
        public static ICalculator CreateCalculator()
        {
            IntPtr instance = NativeMethods.CreateInstance("F3C4F98C-BBDC-4B2E-B67A-12E1475109FE");

            if (instance == IntPtr.Zero) 
                return null;

            return Marshal.GetObjectForIUnknown(instance) as ICalculator;
        }

        class NativeMethods
        {
            [DllImport("CppInterface.dll", CharSet = CharSet.Unicode)]
            public extern static IntPtr CreateInstance(string instanceId);
        }
    }
}
