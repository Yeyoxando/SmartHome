package com.dot.smarthomeapp

import android.os.Bundle
import com.google.android.material.floatingactionbutton.FloatingActionButton
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import android.widget.RadioButton
import com.google.android.material.textfield.TextInputEditText

class MainActivity : AppCompatActivity() {
    var mqtt: MQTTClient = MQTTClient(this)

    override fun onCreate(savedInstanceState: Bundle?) {

        // Connect to MQTT broker
        mqtt.connect()

        super.onCreate(savedInstanceState)
        setContentView(R.layout.fragment_first)
        setSupportActionBar(findViewById(R.id.toolbar))



        bindFirstFragmentButtons()

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
        super.finish()

        // Disconnect from MQTT broker on app finish
        mqtt.disconnect()
    }

    // Used to bind all functions to the buttons of the devices menu
    fun bindFirstFragmentButtons(){
        // OLD TESTS
        /*findViewById<Button>(R.id.button).setOnClickListener {
            //findNavController().navigate(R.id.action_FirstFragment_to_SecondFragment)

            // Here it has to be the message sending
            // Using the mqttClient
            val topic_text = findViewById<TextInputEditText>(R.id.topicText)
            val topic = topic_text.text.toString()

            val message_text = findViewById<TextInputEditText>(R.id.messageText)
            val message = message_text.text.toString()

            mqtt.publish(topic, message)
        }*/


        // LAMP 1
        findViewById<RadioButton>(R.id.radioButtonOnLight1).setOnClickListener {
            mqtt.publish("LED1", "1")
        }
        findViewById<RadioButton>(R.id.radioButtonOffLight1).setOnClickListener {
            mqtt.publish("LED1", "0")
        }

        // FLEXO LAMP
        findViewById<RadioButton>(R.id.radioButtonOnLight2).setOnClickListener {
            mqtt.publish("LED2", "1")
        }
        findViewById<RadioButton>(R.id.radioButtonOffLight2).setOnClickListener {
            mqtt.publish("LED2", "0")
        }

        // RGB LED combinations
        findViewById<RadioButton>(R.id.radioButtonOffLight3).setOnClickListener {
            mqtt.publish("RGBLED", "0")
            turnOffRGBMidRadioButtons()
            turnOffRGBBottomRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonOffLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonWhiteLight3).setOnClickListener {
            mqtt.publish("RGBLED", "1")
            turnOffRGBMidRadioButtons()
            turnOffRGBBottomRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonWhiteLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonRedLight3).setOnClickListener {
            mqtt.publish("RGBLED", "2")
            turnOffRGBTopRadioButtons()
            turnOffRGBBottomRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonRedLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonGreenLight3).setOnClickListener {
            mqtt.publish("RGBLED", "3")
            turnOffRGBTopRadioButtons()
            turnOffRGBBottomRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonGreenLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonBlueLight3).setOnClickListener {
            mqtt.publish("RGBLED", "4")
            turnOffRGBTopRadioButtons()
            turnOffRGBBottomRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonBlueLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonYellowLight3).setOnClickListener {
            mqtt.publish("RGBLED", "5")
            turnOffRGBTopRadioButtons()
            turnOffRGBMidRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonYellowLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonCyanLight3).setOnClickListener {
            mqtt.publish("RGBLED", "6")
            turnOffRGBTopRadioButtons()
            turnOffRGBMidRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonCyanLight3).isChecked = true
        }
        findViewById<RadioButton>(R.id.radioButtonMagentaLight3).setOnClickListener {
            mqtt.publish("RGBLED", "7")
            turnOffRGBTopRadioButtons()
            turnOffRGBMidRadioButtons()
            findViewById<RadioButton>(R.id.radioButtonMagentaLight3).isChecked = true
        }

        // BLIND SERVO MOTOR

        // CEILING FAN DC MOTOR

    }

    fun turnOffRGBTopRadioButtons(){
        findViewById<RadioButton>(R.id.radioButtonOffLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonWhiteLight3).isChecked = false
    }

    fun turnOffRGBMidRadioButtons(){
        findViewById<RadioButton>(R.id.radioButtonRedLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonGreenLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonBlueLight3).isChecked = false
    }

    fun turnOffRGBBottomRadioButtons(){
        findViewById<RadioButton>(R.id.radioButtonYellowLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonCyanLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonMagentaLight3).isChecked = false
    }

}