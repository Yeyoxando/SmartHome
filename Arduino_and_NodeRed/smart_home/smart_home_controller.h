// Author: Diego Ochando Torres
// Date: 08/04/2021
// e-mail: c0022981@my.shu.ac.uk

/** @file smart_home_controller.h
 *  @brief
 *
 *  Details.
 *  \n
*/

#ifndef __SMART_HOME_CONTROLLER_H__
#define __SMART_HOME_CONTROLLER_H__

// ----------------------------------------------------- //

#include "Arduino.h"
#include "devices.h"

// ----------------------------------------------------- //

class SmartHomeController{
 public:
  SmartHomeController();
  ~SmartHomeController();
  
  /// @brief
  void createDevices();

  /// @brief  
  void readInput();
  /// @brief
  void manageDevices();
  
  /// @brief
  void sendCurrentState();
  /// @brief
  void sendDeviceCurrentState(int device_id);
  
 private:
   /// @brief
  Device* devices_[10];
  /// @brief
  String read_string_;
  /// @brief
  int read_number_;
  
};

#endif __SMART_HOME_CONTROLLER_H__
