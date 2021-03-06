using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using OpenCvSharp.Util;

namespace OpenCvSharp
{
    /// <summary>
    /// 
    /// </summary>
    public class VectorOfDouble : DisposableCvObject, IStdVector<double>
    {
        /// <summary>
        /// 
        /// </summary>
        public VectorOfDouble()
        {
            ptr = NativeMethods.vector_double_new1();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="size"></param>
        public VectorOfDouble(int size)
        {
            if (size < 0)
                throw new ArgumentOutOfRangeException(nameof(size));
            ptr = NativeMethods.vector_double_new2(new IntPtr(size));
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="data"></param>
        public VectorOfDouble(IEnumerable<double> data)
        {
            if (data == null)
                throw new ArgumentNullException(nameof(data));
            double[] array = EnumerableEx.ToArray(data);
            ptr = NativeMethods.vector_double_new3(array, new IntPtr(array.Length));
        }

        /// <summary>
        /// Releases unmanaged resources
        /// </summary>
        protected override void DisposeUnmanaged()
        {
            NativeMethods.vector_double_delete(ptr);
            base.DisposeUnmanaged();
        }

        /// <summary>
        /// vector.size()
        /// </summary>
        public int Size
        {
            get { return NativeMethods.vector_double_getSize(ptr).ToInt32(); }
        }

        /// <summary>
        /// &amp;vector[0]
        /// </summary>
        public IntPtr ElemPtr
        {
            get { return NativeMethods.vector_double_getPointer(ptr); }
        }

        /// <summary>
        /// Converts std::vector to managed array
        /// </summary>
        /// <returns></returns>
        public double[] ToArray()
        {
            int size = Size;
            if (size == 0)
            {
                return new double[0];
            }
            double[] dst = new double[size];
            Marshal.Copy(ElemPtr, dst, 0, dst.Length);
            return dst;
        }
    }
}
