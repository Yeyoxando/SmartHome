package com.dot.smarthomeapp

import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.widget.RadioButton
import android.widget.SeekBar
import android.widget.SeekBar.OnSeekBarChangeListener
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

///@ brief Set the connection with the MQTT broker an initialize the app menu.
class MainActivity : AppCompatActivity() {
    // Wrapper for the mqtt client (Data for the broker already set)
    var mqtt: MQTTClient = MQTTClient(this)

    override fun onCreate(savedInstanceState: Bundle?) {

        // Connect to MQTT broker
        mqtt.connect()

        super.onCreate(savedInstanceState)
        setContentView(R.layout.fragment_first)
        setSupportActionBar(findViewById(R.id.toolbar))


        // Set all the actions required for each button of the menu
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

    /// @brief Used to bind all functions of the buttons from the devices menu.
    fun bindFirstFragmentButtons(){

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
            turnOffRGBMidRadioButtons() // This is for the specific implementation of the multiple row radio group, it won't work either
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
        findViewById<SeekBar>(R.id.seekBar).setOnSeekBarChangeListener(object : OnSeekBarChangeListener {
            // Send the value of the seek bar when it's released
            override fun onStopTrackingTouch(seekBar: SeekBar) {
                mqtt.publish("BLIND", findViewById<SeekBar>(R.id.seekBar).progress.toString())
            }

            override fun onStartTrackingTouch(seekBar: SeekBar) {
                // Empty
            }

            override fun onProgressChanged(seekBar: SeekBar, progress: Int, fromUser: Boolean) {
                // Empty
            }
        })

        // CEILING FAN DC MOTOR
        findViewById<SeekBar>(R.id.seekBar2).setOnSeekBarChangeListener(object : OnSeekBarChangeListener {
            // Send the value of the seek bar when it's released
            override fun onStopTrackingTouch(seekBar: SeekBar) {
                mqtt.publish("FAN", findViewById<SeekBar>(R.id.seekBar2).progress.toString())
            }

            override fun onStartTrackingTouch(seekBar: SeekBar) {
                // Empty
            }

            override fun onProgressChanged(seekBar: SeekBar, progress: Int, fromUser: Boolean) {
                // Empty
            }
        })

    }

    /// @brief Turn off the radio buttons from the top row
    fun turnOffRGBTopRadioButtons(){
        findViewById<RadioButton>(R.id.radioButtonOffLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonWhiteLight3).isChecked = false
    }

    /// @brief Turn off the radio buttons from the mid row
    fun turnOffRGBMidRadioButtons(){
        findViewById<RadioButton>(R.id.radioButtonRedLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonGreenLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonBlueLight3).isChecked = false
    }

    /// @brief Turn off the radio buttons from the bottom row
    fun turnOffRGBBottomRadioButtons(){
        findViewById<RadioButton>(R.id.radioButtonYellowLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonCyanLight3).isChecked = false
        findViewById<RadioButton>(R.id.radioButtonMagentaLight3).isChecked = false
    }

}

