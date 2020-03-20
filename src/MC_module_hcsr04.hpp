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

#ifndef mc_module_hcsr04.hpp
#define mc_module_hcsr04.hpp

#include "Arduino.h"

#define CM true
#define INCH false

class MC_M_HCSR04
{
public:
  MC_M_HCSR04(int triggerPin, int echoPin);
  MC_M_HCSR04(int triggerPin, int echoPin, long timeOut);
  long getPulseDuration();
  float getDistance();
  float getDistance(boolean system);

private:
  int triggerPin;
  int echoPin;

  long timeOut = 3000;
  unsigned long timeElapsed = 50;
  unsigned long triggerTime = 10;
  unsigned long earlierTime = 0;
  unsigned long duration = 0;
};

#endif