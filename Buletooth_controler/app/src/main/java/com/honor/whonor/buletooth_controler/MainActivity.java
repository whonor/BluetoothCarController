package com.honor.whonor.buletooth_controler;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.Toast;
import java.io.IOException;
import java.io.OutputStream;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {
private static final String TAG = "Bluetooth_controler";
    private static final boolean D = true;
    private BluetoothAdapter mBluetoothAdapter = null;
    private BluetoothSocket btSocket = null;
    private OutputStream outStream = null;

    Button go;//btn_go;
    Button back;//btn_back;
    Button right;//btn_right;
    Button left;//btn_left;
/*
    private String getUUID(){
        final TelephonyManager tm = (TelephonyManager) getBaseContext().getSystemService(Context.TELEPHONY_SERVICE);

        final String tmDevice, tmSerial, tmPhone, androidId;
        tmDevice = "" + tm.getDeviceId();
        tmSerial = "" + tm.getSimSerialNumber();
        androidId = "" + android.provider.Settings.Secure.getString(getContentResolver(), android.provider.Settings.Secure.ANDROID_ID);

        UUID deviceUuid = new UUID(androidId.hashCode(), ((long)tmDevice.hashCode() << 32) | tmSerial.hashCode());
        String uniqueId = deviceUuid.toString();
        return uniqueId;
    }
*/
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private static final String address = "";//蓝牙模块的MAC地址

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        requestWindowFeature(Window.FEATURE_NO_TITLE);//隐藏标题
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);//设置全屏
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //GO
        go = (Button) findViewById(R.id.btn_go);
        go.setOnTouchListener(new Button.OnTouchListener(){
            @Override
                    public boolean onTouch(View v, MotionEvent event){
                //TODO Auto-generated method stub
                String message;
                byte[] msgBuffer;
                int action = event.getAction();
                switch (action){
                    case MotionEvent.ACTION_DOWN:
                        try {
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "1";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                    case MotionEvent.ACTION_UP:
                        try{
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "0";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                }
                return false;
            }
            });
        //back
        back = (Button) findViewById(R.id.btn_back);
        back.setOnTouchListener(new Button.OnTouchListener(){
            @Override
            public boolean onTouch(View v, MotionEvent event){
                //TODO Auto-generated method stub
                String message;
                byte[] msgBuffer;
                int action = event.getAction();
                switch (action){
                    case MotionEvent.ACTION_DOWN:
                        try {
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "2";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                    case MotionEvent.ACTION_UP:
                        try{
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "0";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                }
                return false;
            }
        });
        //right
        right = (Button) findViewById(R.id.btn_right);
        right.setOnTouchListener(new Button.OnTouchListener(){
            @Override
            public boolean onTouch(View v, MotionEvent event){
                //TODO Auto-generated method stub
                String message;
                byte[] msgBuffer;
                int action = event.getAction();
                switch (action){
                    case MotionEvent.ACTION_DOWN:
                        try {
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "3";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                    case MotionEvent.ACTION_UP:
                        try{
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "0";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                }
                return false;
            }
        });
        //left
        left = (Button) findViewById(R.id.btn_left);
        left.setOnTouchListener(new Button.OnTouchListener(){
            @Override
            public boolean onTouch(View v, MotionEvent event){
                //TODO Auto-generated method stub
                String message;
                byte[] msgBuffer;
                int action = event.getAction();
                switch (action){
                    case MotionEvent.ACTION_DOWN:
                        try {
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "4";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                    case MotionEvent.ACTION_UP:
                        try{
                            outStream = btSocket.getOutputStream();
                        }catch (IOException e){
                            Log.e(TAG, "Output stream creation failed", e);
                        }

                        message = "0";

                        msgBuffer = message.getBytes();

                        try {
                            outStream.write(msgBuffer);
                        }catch (IOException e){
                            Log.e(TAG, "Exception during write", e);
                        }
                        break;
                }
                return false;
            }
        });
        if(D)
            Log.e(TAG, "+++CREATE+++");
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

        if(mBluetoothAdapter == null){
            Toast.makeText(this, "Bluetooth is not available", Toast.LENGTH_LONG).show();
            finish();
            return;
        }

        if (!mBluetoothAdapter.isEnabled()){
            Toast.makeText(this, "Please enable your Bluetooth and re-run this program", Toast.LENGTH_LONG).show();
            finish();
            return;
        }

        if (D)
            Log.e(TAG, "+++ DONE IN ON CREATE, GOT LOCAL BT ADAPTER +++");
    }

    @Override
    public void onStart(){
        super.onStart();
        if (D)
            Log.e(TAG, "++ON START++");
    }

    @Override
    public void onResume(){
        super.onResume();
        if(D){
            Log.e(TAG, "++ON RESUME++");
            Log.e(TAG, "+ABOUT TO ATTEMPT CLIENT CONNECT+");
        }
        BluetoothDevice device = mBluetoothAdapter.getRemoteDevice(address);

        try{
            btSocket = device.createRfcommSocketToServiceRecord(MY_UUID);
        }catch (IOException e){
            Log.e(TAG, "ON RESUME: Socket creation failed.", e);
        }
        mBluetoothAdapter.cancelDiscovery();
        try {

            btSocket.connect();

            Log.e(TAG, "ON RESUME: BT connection established, data transfer link open.");

        } catch (IOException e) {

            try {
                btSocket.close();

            } catch (IOException e2) {

                Log .e(TAG,"ON RESUME: Unable to close socket during connection failure", e2);
            }

        }
        //create date stream
        if (D)
            Log.e(TAG, "+ ABOUT TO SAY SOMETHING TO SERVER +");

    }

    @Override
    public void onPause() {
        super.onPause();
        if (D)
            Log.e(TAG, "- ON PAUSE -");
        if (outStream != null) {
            try {
                outStream.flush();
            } catch (IOException e) {
                Log.e(TAG, "ON PAUSE: Couldn't flush output stream.", e);
            }

        }
        try {
            btSocket.close();
        } catch (IOException e2) {
            Log.e(TAG, "ON PAUSE: Unable to close socket.", e2);
        }
    }
    @Override
    public void onStop() {
        super.onStop();
        if (D)Log.e(TAG, "-- ON STOP --");
    }
    @Override
    public void onDestroy() {
        super.onDestroy();
        if (D) Log.e(TAG, "--- ON DESTROY ---");
    }
}
