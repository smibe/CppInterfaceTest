using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CppInterfaceTest
{
    public class CppInstanceFactory<T> where T : class
    {
        public static CppInterface<T> CreateInstance()
        {
            Guid guid = typeof(T).GUID;
            IntPtr instancePtr = NativeMethods.CreateInstance(guid);

            if (instancePtr == IntPtr.Zero) 
                return null;

            return new CppInterface<T>( Marshal.GetObjectForIUnknown(instancePtr) as T);
        }

    }

    public class NativeMethods
    {
        [DllImport("CppInterface.dll", CharSet = CharSet.Unicode)]
        public extern static IntPtr CreateInstance(Guid guid);
    }
}
