// Author: Diego Ochando Torres
// Date: 08/04/2021
// e-mail: c0022981@my.shu.ac.uk

// ----------------------------------------------------- //

#include "smart_home_controller.h"

// ----------------------------------------------------- //

SmartHomeController::SmartHomeController(){
  
  for(int i = 0; i < 5; ++i){
    devices_[i] = 0;
  }
  
  read_string_ = "";
  read_number_ = -1;
  
}

// ----------------------------------------------------- //

SmartHomeController::~SmartHomeController(){
  
  for(int i = 0; i < 5; ++i){
    if(devices_[i] != 0){
      delete devices_[i];
    }
  }
  
}

// ----------------------------------------------------- //

void SmartHomeController::createDevices(){
  
  Lamp* lamp1 = new Lamp();
  lamp1->setDeviceID(0);
  lamp1->setDigitalPin(2);
  
  devices_[0] = lamp1;
  
  
  Lamp* flexo_lamp = new Lamp();
  flexo_lamp->setDeviceID(1);
  flexo_lamp->setDigitalPin(3);
  
  devices_[1] = flexo_lamp;
  
  
  RGBLamp* rgb_lamp = new RGBLamp();
  rgb_lamp->setDeviceID(2);
  rgb_lamp->setDigitalPin(4);
  rgb_lamp->setGreenPin(5);
  rgb_lamp->setBluePin(6);
  
  devices_[2] = rgb_lamp;


  Blind* blind = new Blind();
  blind->setDeviceID(3);
  blind->setDigitalPin(7);
  blind->initServo();

  devices_[3] = blind;


  CeilingFan* fan = new CeilingFan();
  fan->setDeviceID(4);
  fan->setDigitalPin(11);

  devices_[4] = fan;
    
}

// ----------------------------------------------------- //

void SmartHomeController::readInput(){
  
  // Read only while input is received
  while(Serial.available() > 0){
    char c = Serial.read();
    read_string_ += c;
    delay(2);
  }
  
  if(read_string_ != ""){ // If the string contains anything
    Serial.println(read_string_);  
    read_number_ = read_string_.toInt();
    Serial.println(read_number_);
  }
  else{
    // Reset if it's empty
    read_number_ = -1;
  }
  
}

// ----------------------------------------------------- //

void SmartHomeController::manageDevices(){

  // Fan tick for PMW
  devices_[4]->tick();
  
  // Split the number (tens place is for device ID, units place is for device state)
  int device_id = read_number_ / 10;
  int device_state = read_number_ % 10;

  // The function is called for each device specifically as it is virtual and its overriden in
  // each device class
  devices_[device_id]->setCurrentState(device_state);
  
  // Reset input variables
  read_number_ = -1;
  read_string_ = "";
  
}

// ----------------------------------------------------- //
