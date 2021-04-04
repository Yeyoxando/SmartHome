package com.dot.smarthomeapp

import android.os.Bundle
import com.google.android.material.floatingactionbutton.FloatingActionButton
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import com.google.android.material.textfield.TextInputEditText

class MainActivity : AppCompatActivity() {
    var mqtt: MQTTClient = MQTTClient(this)

    override fun onCreate(savedInstanceState: Bundle?) {

        // Connect to MQTT broker
        mqtt.connect()

        super.onCreate(savedInstanceState)
        setContentView(R.layout.fragment_first)
        setSupportActionBar(findViewById(R.id.toolbar))

        findViewById<Button>(R.id.button).setOnClickListener {
            //findNavController().navigate(R.id.action_FirstFragment_to_SecondFragment)

            // Here it has to be the message sending
            // Using the mqttClient
            val topic_text = findViewById<TextInputEditText>(R.id.topicText)
            val topic = topic_text.text.toString()

            val message_text = findViewById<TextInputEditText>(R.id.messageText)
            val message = message_text.text.toString()

            mqtt.publish(topic, message)
        }

        findViewById<Button>(R.id.radioButtonOnLight1).setOnClickListener {
            mqtt.publish("LED1", "1")
        }
        findViewById<Button>(R.id.radioButtonOffLight1).setOnClickListener {
            mqtt.publish("LED1", "0")
        }
        findViewById<Button>(R.id.radioButtonOnLight2).setOnClickListener {
            mqtt.publish("LED2", "1")
        }
        findViewById<Button>(R.id.radioButtonOffLight2).setOnClickListener {
            mqtt.publish("LED2", "0")
        }

    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        return when (item.itemId) {
            R.id.action_settings -> true
            else -> super.onOptionsItemSelected(item)
        }
    }

    override fun finish() {
        // Disconnect from MQTT broker on app finish
        super.finish()
        mqtt.disconnect()
    }
}