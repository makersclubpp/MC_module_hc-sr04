/**
 * 
 * \file MC_module_hc-sr04.h
 * \brief
 * 
 * Makers Club
 * 
 * \details description:
 * \author autor:
 * \version
 * \date creation date:
 * \date modification date:
 * 
 */

#ifndef mc_module_hcsr04.h
#define mc_module_hcsr04 .h

#include "Arduino.h"

#define CM true
#define INCH false

class HCSR04
{
public:
  HCSR04(int triggerPin, int echoPin);
  HCSR04(int triggerPin, int echoPin, long timeOut);
  long pulseDuration();
  float distance();
  float distance(boolean system);

private:
  int triggerPin;
  int echoPin;
  long timeOut = 3000;
};

#endif