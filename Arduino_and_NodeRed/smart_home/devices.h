// Author: Diego Ochando Torres
// Date: 02/04/2021
// e-mail: c0022981@my.shu.ac.uk

#ifndef __DEVICES_H__
#define __DEVICES_H__

/** @file devices.h
 *  @brief All the electronic devices implemented in the Arduino smart home in OOP representation.
 *
 *  Details.
 *  Each device is a child from the parent Device class, which defines the basic funcionality
 *  of all the devices. After that, using the C++ class inheritance, each one implements this funtionality
 *  specifically for its behaviour. They also include extra functions and data.
*/

// ----------------------------------------------------- //

#include <Servo.h>

// ----------------------------------------------------- //

/// @brief Parent class, cannot be created. Defines essential functionalaty for all devices.
class Device {
 public:
  ~Device();
   
  /// @brief Definition of the different implemented "devices".
  enum DeviceKind{
    kDeviceKind_Invalid = 0,
    kDeviceKind_Lamp = 1,
    kDeviceKind_RGBLamp = 2,
    kDeviceKind_Blind = 3,
    kDeviceKind_CeilingFan = 4
  };
   
  /// @brief Stores the device ID for later identification when reading input.
  void setDeviceID(int new_id);
  /// @brief Stores the digital pin of the arduino where it is attached.
  void setDigitalPin(int digital_pin);
 
  /// @brief Specifically implemented in children classed. Return the current state of the device.
  virtual int getCurrentState() {}
  /// @brief Specifically implemented in children classed. Set the new current state of the device.
  virtual void setCurrentState(int new_state) {}
  
  /// @brief Specifically implemented in children classed. Used if a device needs to be updated repeatedly.
  virtual void tick() {}
 
 protected:
  /// @brief Constructor is privated as the Devices has to be created with children classes.
  Device();

  int device_id_;
  int digital_pin_;
  DeviceKind device_kind_;
  
};

// ----------------------------------------------------- //

/// @brief This "device" is represented by a standard LED.
class Lamp : public Device{
 public:
  Lamp();
  ~Lamp();
 
  /// @brief The lamp can only be turned on or off.
  enum LampState{
    kLampState_Off = 0,
    kLampState_On = 1
  };
 
  /// @brief Returns the current state of the lamp.
  virtual int getCurrentState() override;
  /// @brief Set a new state between one of the defined in this class.
  virtual void setCurrentState(int new_state) override;
  
  /// @brief Not used in this device.
  virtual void tick() override {}
 
 protected:
  LampState current_state_;
   
};

// ----------------------------------------------------- //

/// @brief This "device" is represented by an RGB LED.
class RGBLamp : public Lamp{
 public:
  RGBLamp();
  ~RGBLamp();
 
  // Red pin is set with set digital pin from Device parent class
  /// @brief Set another digital pin for the green channel output.
  void setGreenPin(int digital_pin);
  /// @brief Set another digital pin for the blue channel output.
  void setBluePin(int digital_pin);
 
  /// @brief Different color state combinations for the RGB lamp.
  enum RGBLampState{
    kRGBLampState_Off = 0,
    kRGBLampState_White = 1,
    kRGBLampState_Red = 2,
    kRGBLampState_Green = 3,
    kRGBLampState_Blue = 4,
    kRGBLampState_Yellow = 5,
    kRGBLampState_Cyan = 6,
    kRGBLampState_Magenta = 7
  };
 
  /// @brief Returns the current state of the RGB lamp.
  virtual int getCurrentState() override;
  /// @brief Set a new state between one of the defined in this class.
  virtual void setCurrentState(int new_state) override;
  
  /// @brief Not used in this device.
  virtual void tick() override {}
 
 protected:
  int green_pin_;
  int blue_pin_;

  RGBLampState current_state_;
  
};

// ----------------------------------------------------- //

/// @brief This "device" is represented by a servo motor.
class Blind : public Device{
 public:
  Blind();
  ~Blind();

  /// @brief Initializes the servo motor in its previously indicated digital pin.
  void initServo();
  
  /// @brief The blind angle can be set in steps of 20%, from fully closed to fully open.
  enum BlindState{
    kBlindState_Closed = 0,
    kBlindState_20Percent = 1,
    kBlindState_40Percent = 2,
    kBlindState_60Percent = 3,
    kBlindState_80Percent = 4,
    kBlindState_Open = 5
  };
 
  /// @brief Returns the current state of the blind.
  virtual int getCurrentState() override;
  /// @brief Set a new state between one of the defined in this class.
  virtual void setCurrentState(int new_state) override;
  
  /// @brief Not used in this device.
  virtual void tick() override {}
   
 protected:
  /// @brief Servo object from the Arduino library.
  Servo servo_;
  /// @brief current angle of the servo motor.
  int angle_;

  BlindState current_state_;
  
};

// ----------------------------------------------------- //

/// @brief This "device" is represented by a DC motor.
class CeilingFan : public Device{
 public:
  CeilingFan();
  ~CeilingFan();
 
  /// @brief Speed of the DC motor is modifiable using PMW and a MOSFET transistor.
  enum CeilingFanState{
    kCeilingFanState_Off = 0,
    kCeilingFanState_MidSpeed = 1,
    kCeilingFanState_FullSpeed = 2
  };
 
  /// @brief Returns the current state of the fan.
  virtual int getCurrentState() override;
  /// @brief Set a new state between one of the defined in this class.
  virtual void setCurrentState(int new_state) override;
  
  /// @brief Used to send the PMW with a delay between them.
  virtual void tick() override;
   
 protected:
  CeilingFanState current_state_;
  
};

// ----------------------------------------------------- //

#endif //__DEVICES_H__
