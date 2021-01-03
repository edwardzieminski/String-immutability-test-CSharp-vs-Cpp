using System;

namespace CSharpSamples
{
    public static class RefHelper
    {
        // Method inspired by: https://stackoverflow.com/a/10861731/13721565
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
