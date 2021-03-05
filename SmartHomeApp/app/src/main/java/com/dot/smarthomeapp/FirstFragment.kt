package com.dot.smarthomeapp

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import androidx.navigation.fragment.findNavController
import com.google.android.material.textfield.TextInputEditText

class FirstFragment : Fragment() {

    override fun onCreateView(
            inflater: LayoutInflater, container: ViewGroup?,
            savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_first, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        view.findViewById<Button>(R.id.button).setOnClickListener {
            //findNavController().navigate(R.id.action_FirstFragment_to_SecondFragment)

            // Here it has to be the message sending
            // Using the mqttClient
            val topic_text = (activity as MainActivity).findViewById(R.id.topicText) as TextInputEditText
            val topic = topic_text.text.toString()

            val message_text = (activity as MainActivity).findViewById(R.id.messageText) as TextInputEditText
            val message = message_text.text.toString()

            (activity as MainActivity).mqtt.publish(topic, message)
        }
    }
}