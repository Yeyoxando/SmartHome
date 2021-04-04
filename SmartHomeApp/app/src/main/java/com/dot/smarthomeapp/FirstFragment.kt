package com.dot.smarthomeapp

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import com.google.android.material.textfield.TextInputEditText

class FirstFragment : Fragment() {

    override fun onCreateView(
            inflater: LayoutInflater, container: ViewGroup?,
            savedInstanceState: Bundle?
    ): View? {

        /*findViewById<Button>(R.id.button).setOnClickListener {
            //findNavController().navigate(R.id.action_FirstFragment_to_SecondFragment)

            // Here it has to be the message sending
            // Using the mqttClient
            val topic_text = R.id.topicText
            val topic = topic_text.text.toString()

            val message_text = (R.id.messageText)
            val message = message_text.text.toString()

            mqtt.publish(topic, message)
        }*/

        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_first, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
    }
}
