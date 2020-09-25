package com.wzq.ndk

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import java.io.File
import java.io.FileOutputStream

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        sample_text.text = stringFromJNI()



        Thread {
            val file = externalCacheDir
            val newFile = File(file, "text.txt")
            newFile.createNewFile()
            val newFile11 = File(file, "text11.txt")
            newFile11.createNewFile()
            val fileOutputStream = FileOutputStream(newFile)
            fileOutputStream.write(0)
            fileOutputStream.write(1)
            fileOutputStream.write(2)
            fileOutputStream.write(3)
            fileOutputStream.write(4)
            fileOutputStream.flush()
            fileOutputStream.close()
            fileRead(newFile.absolutePath, newFile11.absolutePath)
        }.start()


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun fileRead(path: String,path1: String)

    fun textJni(data: String) {
        Log.e(TAG, "data is $data")

    }

    companion object {
        // Used to load the 'native-lib' library on application startup.

        val TAG = "MainActivity"
        fun staticTextJni(data: String) {
            Log.e(TAG, "staticTextJni is $data")

        }

        init {
            System.loadLibrary("native-lib")


        }
    }
}
