// Author: Diego Ochando Torres
// Date: 02/04/2021
// e-mail: c0022981@my.shu.ac.uk

#include "devices.h"
#include "Arduino.h"

// ----------------------------------------------------- //

// ------------------- DEVICE BASE --------------------- //

void Device::setDeviceID(int new_id){
  device_id_ = new_id;
}

void Device::setDigitalPin(int digital_pin){
  digital_pin_ = digital_pin;
  pinMode(digital_pin, OUTPUT);
  digitalWrite(digital_pin, LOW);
}
 
Device::Device(){
  device_kind_ = kDeviceKind_Invalid;
  device_id_ = -1;
  digital_pin_ = 0;
}

Device::~Device(){

}
   
// ----------------------------------------------------- //

// ----------------------------------------------------- //

// ---------------------- LAMP ------------------------- //

Lamp::Lamp(){
  device_kind_ = kDeviceKind_Lamp;
  current_state_ = kLampState_Off;
}

Lamp::~Lamp(){

}
 
int Lamp::getCurrentState(){
  return (int)current_state_;
}

void Lamp::setCurrentState(int new_state){
  if(new_state == kLampState_On){
    digitalWrite(digital_pin_, HIGH);
  }
  else if(new_state == kLampState_Off){
    digitalWrite(digital_pin_, LOW);
  }
}
   
// ----------------------------------------------------- //

// ----------------------------------------------------- //

// -------------------- RGB LAMP ----------------------- //

RGBLamp::RGBLamp(){
  device_kind_ = kDeviceKind_RGBLamp;
  current_state_ = kRGBLampState_Off;
  green_pin_ = 0;
  blue_pin_ = 0;
}

RGBLamp::~RGBLamp(){

}
 
void RGBLamp::setGreenPin(int digital_pin){
  green_pin_ = digital_pin;
  pinMode(digital_pin, OUTPUT);
  digitalWrite(digital_pin, LOW);
}

void RGBLamp::setBluePin(int digital_pin){
  blue_pin_ = digital_pin;
  pinMode(digital_pin, OUTPUT);
  digitalWrite(digital_pin, LOW);
}
 
int RGBLamp::getCurrentState(){
  return (int)current_state_;
}

void RGBLamp::setCurrentState(int new_state){
  switch(new_state){
  case kRGBLampState_Off:{
    digitalWrite(digital_pin_, LOW);
    digitalWrite(green_pin_, LOW);
    digitalWrite(blue_pin_, LOW);
    break;
  }
  case kRGBLampState_White:{
    digitalWrite(digital_pin_, HIGH);
    digitalWrite(green_pin_, HIGH);
    digitalWrite(blue_pin_, HIGH);
    break;
  }
  case kRGBLampState_Red:{
    digitalWrite(digital_pin_, HIGH);
    digitalWrite(green_pin_, LOW);
    digitalWrite(blue_pin_, LOW);
    break;
  }
  case kRGBLampState_Green:{
    digitalWrite(digital_pin_, LOW);
    digitalWrite(green_pin_, HIGH);
    digitalWrite(blue_pin_, LOW);
    break;
  }
  case kRGBLampState_Blue:{
    digitalWrite(digital_pin_, LOW);
    digitalWrite(green_pin_, LOW);
    digitalWrite(blue_pin_, HIGH);
    break;
  }
  case kRGBLampState_Yellow:{
    digitalWrite(digital_pin_, HIGH);
    digitalWrite(green_pin_, HIGH);
    digitalWrite(blue_pin_, LOW);
    break;
  }
  case kRGBLampState_Cyan:{
    digitalWrite(digital_pin_, LOW);
    digitalWrite(green_pin_, HIGH);
    digitalWrite(blue_pin_, HIGH);
    break;
  }
  case kRGBLampState_Magenta:{
    digitalWrite(digital_pin_, HIGH);
    digitalWrite(green_pin_, LOW);
    digitalWrite(blue_pin_, HIGH);
    break;
  }
  default:{
    break;
  }
  }
}
 
// ----------------------------------------------------- //

// ----------------------------------------------------- //

// ---------------------- BLIND ------------------------ //

Blind::Blind(){
  device_kind_ = kDeviceKind_Blind;
  current_state_ = kBlindState_Closed;
  custom_angle_ = 0;
}

Blind::~Blind(){

}

void Blind::setDegrees(int new_degrees){

}
 
int Blind::getCurrentState(){
  return (int)current_state_;
}

void Blind::setCurrentState(int new_state){

}
   
// ----------------------------------------------------- //

// ----------------------------------------------------- //

// ------------------- CEILING FAN --------------------- //

CeilingFan::CeilingFan(){
  device_kind_ = kDeviceKind_CeilingFan;
}

CeilingFan::~CeilingFan(){

}

int CeilingFan::getCurrentState(){
  return (int)current_state_;
}

void CeilingFan::setCurrentState(int new_state){

}
   
// ----------------------------------------------------- //
   
// ----------------------------------------------------- //

