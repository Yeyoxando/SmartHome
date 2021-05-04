// Author: Diego Ochando Torres
// Date: 08/04/2021
// e-mail: c0022981@my.shu.ac.uk

#ifndef __SMART_HOME_CONTROLLER_H__
#define __SMART_HOME_CONTROLLER_H__

/** @file smart_home_controller.h
 *  @brief OOP Representation of the Arduino smart home. 
 *
 *  Details. 
 *  It contain all the implemented devices and read the input 
 *  sent from the Raspberry MQTT broker. 
*/

// ----------------------------------------------------- //

#include "Arduino.h"
#include "devices.h"

// ----------------------------------------------------- //

/// @brief Arduino smart home. 
class SmartHomeController{
 public:
  SmartHomeController();
  ~SmartHomeController();
  
  /// @brief Creates all the electronic devices connections and their settings.
  void createDevices();

  /// @brief Read the input from through the Serial from the MQTT broker.
  void readInput();
  /// @brief Send the readen data to the devices to change their state.
  void manageDevices();
  
 private:
  /// @brief Stored devices installed on the house, store their variables and state.
  Device* devices_[5];
  /// @brief Readen string from the Serial port communication.
  String read_string_;
  /// @brief Readen string transformed to an integer.
  int read_number_;
  
};

// ----------------------------------------------------- //

#endif //__SMART_HOME_CONTROLLER_H__
