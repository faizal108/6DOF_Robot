#include <math.h>
#include "Emergency.h"
#include "Drivers.h"
#include "ControlButton.h"
#include "InitialConfig.h"
#include "LimitSwitch.h"
#include "RobotGeometry.h"

boolean calibrationStatus = false;

void setup()
{
  Serial.begin(115200);
  delay(20);
  setupEmergencyStop();
  setupDrivers();
  setupControlButton();
  setupLimitSwitch(); 

  while(!calibrationStatus);  
}

void loop()
{
  checkButtons();
  // Check for incoming data
  checkSerial();
}
