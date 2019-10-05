package com.xusu.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView mTv = findViewById(R.id.tv_text);
        Hello.staticMethod("");//调用java静态方法

        Hello.callStaticMethod(1);//c 调用java静态方法

        Hello.logMessage("------------------\n");
        Hello hello = new Hello();
        hello.callInstanceMethod(1);//c 调用java实例方法
//        hello.method(hello.getAddress());
        mTv.setText(hello.stringFromJNI());
    }
}
