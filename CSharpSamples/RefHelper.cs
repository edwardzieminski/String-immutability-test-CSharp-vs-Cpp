using System;

namespace CSharpSamples
{
    public static class RefHelper
    {
        public static string Ref(this object o)
        {
            unsafe
            {
                var reference = __makeref(o);
                var pointer = **(IntPtr**)&reference;
                return pointer.ToString();
            }
        }
    }
}
