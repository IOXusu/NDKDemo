package com.xusu.ndkdemo;

import android.util.Log;

public class Hello {

    static {
        System.loadLibrary("hello");
    }

    public native static String stringFromJNI();

    public static void logMessage(String data) {
        Log.d("nate", data);
    }


    /**
     * c 调用 java静态方法 staticMethod()
     *
     * @param i
     */
    public static native void callStaticMethod(int i);

    public static String name = "javaName";

    public static void staticMethod(String data) {
        logMessage(data);
        logMessage(name);
    }


    /**
     * c 调用 java实例方法 method()
     *
     * @param i
     */
    public native void callInstanceMethod(int i);

    private String address = "beijing";


    public void method(String data) {
        logMessage(data);
        Hello.logMessage(address);
    }

}
