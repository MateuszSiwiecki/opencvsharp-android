using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Dg = System.Diagnostics.Debug;
using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.Graphics;
using OpenCvSharp.Native;
using Java.Nio;

namespace OpenCvSharp.Android
{
    public class NativeBinding : NativeBindings
    {
        public static NativeBinding K => (NativeBinding)Kernal;

        public volatile bool SurfaceAvalible;

        public static void Init(Context context, Activity activity, ImageView imShowTarget = null)
        {
            Kernal = new NativeBinding(context, activity, imShowTarget);
        }

        public Context AppContext;
        public Activity MainActivity;
        public ImageView ImShowTarget;

        public NativeBinding(Context context, Activity activity, ImageView imShowTarget = null)
        {
            AppContext = context;
            MainActivity = activity;
            ImShowTarget = imShowTarget;
        }

        Bitmap imShowBitmap;
        byte[] imShowBuffer;
        public object locker1 = new object();
        public object locker2 = new object();
        public object locker3 = new object();
        public object locker4 = new object();
        public override void ImShow(string name, Mat m) => ImShow(name, m, ImShowTarget, locker1);
        public void ImShow(string name, Mat m, ImageView tagetView) => ImShow(name, m, tagetView, locker2);
        public void ImShow(string name, Mat m, ImageView tagetView, object lockObject)
        {
            if (tagetView != null)
            {
                lock (lockObject)
                {
                    CvProfiler.Start($"imshow {name}");
                    var toShow = Bitmap.CreateBitmap(m.Width, m.Height, Bitmap.Config.Argb8888);

                    using (Mat mat = new Mat())
                    {
                        Cv2.CvtColor(m, mat, ColorConversionCodes.BGRA2RGBA);

                        var bufLen = mat.Channel * mat.Total();
                        var buffer = new byte[bufLen];
                        mat.GetArray(0, 0, buffer);

                        using (var raw = ByteBuffer.Wrap(buffer))
                        {
                            toShow.CopyPixelsFromBuffer(raw);
                        }

                        //MainActivity.RunOnUiThread(() =>
                        //{
                        tagetView.SetImageBitmap(toShow);
                        //});
                    }
                    CvProfiler.End($"imshow {name}");
                }
            }
        }
        public void ImShow(string name, Mat m, TextureView tagetView) => ImShow(name, m, tagetView, locker3);
        private Bitmap toShow;
        private byte[] toShowBuffer;
        public static readonly object SurfaceLocker = new object();
        public void ImShow(string name, Mat m, TextureView tagetView, object lockObject)
        {
            if (tagetView != null)
            {
                lock (lockObject)
                {
                    if (toShow == null || (toShow.Width != m.Width && toShow.Height != m.Height))
                        toShow = Bitmap.CreateBitmap(m.Width, m.Height, Bitmap.Config.Argb8888);

                    using (Mat mat = new Mat())
                    {
                        Cv2.CvtColor(m, mat, ColorConversionCodes.BGRA2RGBA);

                        var bufLen = mat.Channel * mat.Total();
                        if (toShowBuffer == null || toShowBuffer.Length != bufLen)
                        {
                            toShowBuffer = new byte[bufLen];
                        }
                        mat.GetArray(0, 0, toShowBuffer);

                        using (var raw = ByteBuffer.Wrap(toShowBuffer))
                        {
                            toShow.CopyPixelsFromBuffer(raw);
                        }

                        Dg.WriteLine("SHOW START");

                        lock (SurfaceLocker)
                        {
                            Dg.WriteLine("LockCanvas");
                            Dg.WriteLine($"Surface avalible {SurfaceAvalible}");
                            if (!SurfaceAvalible)
                            {
                                Dg.WriteLine($"Surface not avalible, SHOW END");
                                return;
                            }
                            if (toShow == null) return;
                            
                                                    
                            var canvas = tagetView.LockCanvas();
                            if (canvas == null) return;

                            var paint = new Paint();
                            var clearPaint = new Paint();
                            clearPaint.SetXfermode(new PorterDuffXfermode(PorterDuff.Mode.Clear));

                            Dg.WriteLine("DrawPaint");

                            Dg.WriteLine($"targetView {tagetView == null}");
                            Dg.WriteLine($"tagetView.SurfaceTexture {tagetView.SurfaceTexture == null}");
                            Dg.WriteLine($"tagetView.SurfaceTexture.IsReleased {tagetView.SurfaceTexture.IsReleased}");
                            Dg.WriteLine($"canvas {canvas == null}");
                            Dg.WriteLine($"toShow {toShow == null}");
                            Dg.WriteLine($"toShow.IsRecycled {toShow.IsRecycled}");

                            canvas.DrawPaint(clearPaint);
                            paint.SetXfermode(new PorterDuffXfermode(PorterDuff.Mode.DstAtop));

                            Dg.WriteLine("DrawBitmap");
                            canvas.DrawBitmap(toShow, new Matrix(), paint);

                            Dg.WriteLine("UnlockCanvasAndPost");
                            tagetView.UnlockCanvasAndPost(canvas);

                            Dg.WriteLine("SHOW END");
                        }
                    }
                }
            }
        }

        char keyPending = (char)255;
        public void SendKey(char key)
        {
            keyPending = key;
        }

        public override int WaitKey(int sleep = 0)
        {
            var ret = keyPending;

            Sleep(sleep);

            keyPending = (char)255;
            return ret;
        }

        public override void Sleep(int sleep = 0)
        {
            if (sleep <= 0)
            {
                while (true)
                {
                    if (keyPending != 255)
                    {
                        Sleep(1);
                        break;
                    }
                }
            }
            else
            {
                System.Threading.Thread.Sleep(sleep);
            }
        }

        public Capture NewCapture(int index, int sizes)
        {
            return new AndroidCapture(index, sizes);
        }
        public override Capture NewCapture(int index)
        {
            return new AndroidCapture(index);
        }

        public override Capture NewCapture(string file)
        {
            return new AndroidCapture(file);
        }

        public override void NamedWindow(string winname, WindowMode flags)
        {

        }

        public override void DestroyAllWindows()
        {

        }
    }
}