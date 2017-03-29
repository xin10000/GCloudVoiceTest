package com.noteam.werewolves;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.tencent.gcloud.voice.GCloudVoiceEngine;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    boolean poll;

    String roomName = "mytest";
    EditText etOpenId;
    EditText etRoomName;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etOpenId = (EditText) findViewById(R.id.etOPenId);
        etRoomName = (EditText) findViewById(R.id.etRoomName);
        GCloudVoiceEngine.getInstance().init(getApplicationContext(), this);

    }

    public void onBtnClick(View v) {
        int result;
        switch (v.getId()) {
            case R.id.btnOpenSpeaker:
               
                result =  openSpeaker();
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
                break;
            case R.id.btnInit:
                 result = initGC( etOpenId.getText().toString());
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
                break;
            case R.id.btnOpenMic:
                result =  openMic();
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
               
                break;

            case R.id.btnJoinTeamRoom:
                roomName ="mytest";
                if (etRoomName.getText().length()>0) {
                    roomName=etRoomName.getText().toString();
                }
                 result =joinTeamRoom(roomName);
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
                
                break;

            case R.id.btnPoll:
                poll = !poll;
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        while (poll) {
                            try {
                                Thread.sleep(50);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                            poll();
                        }
                    }
                }).start();
                break;

            case R.id.btnCloseMic:
                result = closeMic();
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
               
                break;
            case R.id.btnCloseSpeaker:
                result =closeSpeaker();
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
                
                break;

            case R.id.btnQuitRoom:
                result = quitRoom(roomName);
                Toast.makeText(MainActivity.this, result + "", Toast.LENGTH_SHORT).show();
                quitRoom(roomName);
                break;
        }
    }

    @Override
    protected void onStop() {
        super.onStop();
//        int i = quitRoom(roomName);
//        Log.e(TAG, "onStop: " + i);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        quitRoom(roomName);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int initGC(String openId);

    public native int joinTeamRoom(String roomName);

    public native int quitRoom(String roomName);

    public native int openMic();

    public native int closeMic();

    public native int closeSpeaker();

    public native int openSpeaker();

    public native int poll();
}
