// emergency.h

#ifndef EMERGENCY
#define EMERGENCY

// Include necessary libraries if needed
#include <Arduino.h>

// Define emergency button pin
const int emergencyButtonPin = 18;

// Flag to indicate emergency stop
volatile bool emergencyStop = false;

// Function prototype and implementation for the emergency stop interrupt
void emergencyStopInterrupt() {
  // Set the emergencyStop flag to true
  emergencyStop = true;
}

// Function to set up emergency stop
void setupEmergencyStop() {
  // Set up emergency button pin
  pinMode(emergencyButtonPin, INPUT_PULLUP);

  // Attach interrupt to the emergency button pin
  attachInterrupt(digitalPinToInterrupt(emergencyButtonPin), emergencyStopInterrupt, FALLING);
}

#endif  // EMERGENCY_H
