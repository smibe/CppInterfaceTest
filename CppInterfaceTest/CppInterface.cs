using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CppInterfaceTest
{
    public class CppInterface<T> : IDisposable
    {
        private T cppInterface;
        public CppInterface(T cppInterface)
        {
            this.cppInterface = cppInterface;
        }

        public T Object { get { return this.cppInterface; } }

        public void Dispose()
        {
            Marshal.ReleaseComObject(this.cppInterface);
        }
    }
}
