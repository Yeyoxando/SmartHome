// Author: Diego Ochando Torres
// Date: 02/04/2021
// e-mail: c0022981@my.shu.ac.uk

/** @file devices.h
 *  @brief
 *
 *  Details.
 *  \n
*/

#ifndef __DEVICES_H__
#define __DEVICES_H__

// ----------------------------------------------------- //

/// @brief
class Device {
 public:
  ~Device();
   
  /// @brief
  enum DeviceKind{
    kDeviceKind_Invalid = 0,
    kDeviceKind_Lamp = 1,
    kDeviceKind_RGBLamp = 2,
    kDeviceKind_Blind = 3,
    kDeviceKind_CeilingFan = 4
  };
   
  /// @brief
  void setDeviceID(int new_id);
  /// @brief
  void setDigitalPin(int digital_pin);
 
  /// @brief
  virtual int getCurrentState() {}
  /// @brief 
  virtual void setCurrentState(int new_state) {}
 
 protected:
  /// @brief
  Device();

  /// @brief 
  int device_id_;
  /// @brief
  int digital_pin_;
  /// @brief
  DeviceKind device_kind_;
  
};

// ----------------------------------------------------- //

/// @brief
class Lamp : public Device{
 public:
  Lamp();
  ~Lamp();
 
  /// @brief
  enum LampState{
    kLampState_Off = 0,
    kLampState_On = 1
  };
 
  /// @brief
  virtual int getCurrentState() override;
  /// @brief
  virtual void setCurrentState(int new_state) override;
 
 protected:
  /// @brief
  LampState current_state_;
   
};

// ----------------------------------------------------- //

/// @brief
class RGBLamp : public Lamp{
 public:
  RGBLamp();
  ~RGBLamp();
 
  // Red pin is set with set digital pin from Device parent class
  /// @brief
  void setGreenPin(int digital_pin);
  /// @brief
  void setBluePin(int digital_pin);
 
  /// @brief
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
 
  /// @brief
  virtual int getCurrentState() override;
  /// @brief
  virtual void setCurrentState(int new_state) override;
 
 protected:
  /// @brief
  int green_pin_;
  /// @brief
  int blue_pin_;
  /// @brief
  RGBLampState current_state_;
  
};

// ----------------------------------------------------- //

/// @brief
class Blind : public Device{
 public:
  Blind();
  ~Blind();
 
  /// @brief
  void setDegrees(int new_degrees);
 
  /// @brief
  enum BlindState{
    kBlindState_Closed = 0,
    kBlindState_Custom = 1,
    kBlindState_Open = 2
  };
 
  /// @brief
  virtual int getCurrentState() override;
  /// @brief
  virtual void setCurrentState(int new_state) override;
   
 protected:
  /// @brief
  BlindState current_state_;
  /// @brief
  int custom_angle_; // stepped in 20º
  
};

// ----------------------------------------------------- //

/// @brief
class CeilingFan : public Device{
 public:
  CeilingFan();
  ~CeilingFan();
 
  /// @brief
  enum CeilingFanState{
    kCeilingFanState_Off = 0,
    kCeilingFanState_MidSpeed = 1,
    kCeilingFanState_FullSpeed = 2
  };
 
  /// @brief
  virtual int getCurrentState() override;
  /// @brief
  virtual void setCurrentState(int new_state) override;
   
 protected:
  /// @brief
  CeilingFanState current_state_;
  
};

// ----------------------------------------------------- //

#endif __DEVICES_H__
