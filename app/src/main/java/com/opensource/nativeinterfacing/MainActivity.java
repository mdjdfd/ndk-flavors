package com.opensource.nativeinterfacing;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private native String getJNIString();
    private native int doJNIAddition(int a, int b);
    private native boolean doJNICompare(int a, int b);
    private native User createJNIUser(int age);
    private native int getJNIUser(User user);

    static{
        try {
            System.loadLibrary("io-ndk");
        } catch (UnsatisfiedLinkError e) {
            e.printStackTrace();
        }
    }

    private TextView mTv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        init();

    }

    private void init() {
        mTv = findViewById(R.id.text_view);
        User user = createJNIUser(28);
        mTv.setText(String.valueOf(getJNIUser(user)));
    }
}