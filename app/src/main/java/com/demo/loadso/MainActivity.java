package com.demo.loadso;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    private String libpath;
    private TextView tv;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        tv = (TextView) findViewById(R.id.sample_text);

        Button loadhelloworld = (Button)findViewById(R.id.loadhelloworld);
        Button unloadhelloworld = (Button)findViewById(R.id.unloadhelloworld);
        final Button loadhellocolor = (Button)findViewById(R.id.loadhellocolor);
        Button unloadhellocolor = (Button)findViewById(R.id.unloadhellocolor);
        //get libs path
        libpath = this.getApplicationInfo().nativeLibraryDir;
        unloadhellocolor.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(unLoadHelloColor());
            }
        });
        loadhellocolor.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(loadHelloColor(libpath+ "/libhellocolor.so"));
            }
        });
        loadhelloworld.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv.setText(loadHelloWorld(libpath+ "/libhelloworld.so"));
            }
        });
        unloadhelloworld.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                tv.setText(unLoadHelloWorld());
            }
        });

        tv.setText(stringFromJNI());

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String loadHelloWorld(String path);

    public native String unLoadHelloWorld();

    public native String loadHelloColor(String path);

    public native String unLoadHelloColor();


}
