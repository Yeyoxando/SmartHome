// Author: Diego Ochando Torres
// Date: 02/04/2021
// e-mail: c0022981@my.shu.ac.uk

#include "smart_home_controller.h"

/*
* Pin  2: Lamp
* Pin  3: Flexo lamp
* Pins 4, 5, 6: RGB LAMP (R, G, B)
* Pin  7: Blind Servo
* Pin 11: Ceiling fan (PMW)
*/

SmartHomeController smart_home;

// ----------------------------------------------------- //

void setup(){
  
  Serial.begin(9600);

  smart_home.createDevices();

}

// ----------------------------------------------------- //

void loop(){
  
  smart_home.readInput();
  
  smart_home.manageDevices();
  
}

// ----------------------------------------------------- //
