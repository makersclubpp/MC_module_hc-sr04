/**
 * 
 * \file MC_module_HCSR04.c
 * \brief
 *  
 */

#include "Arduino.h"
#include "mc_module_hcsr04.hpp"

MC_M_HCSR04::MC_M_HCSR04(int triggerPin, int echoPin)
{
    MC_M_HCSR04(triggerPin, echoPin, this->timeOut);
}

MC_M_HCSR04::MC_M_HCSR04(int triggerPin, int echoPin, long timeOut)
{
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->timeOut = timeOut;

    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);

    digitalWrite(this->triggerPin, LOW);

    this->timeElapsed = millis();
    this->duration = millis();
}

long MC_M_HCSR04::pulseDuration()
{
    if ((millis() - this->earlierTime) > this->timeElapsed)
    {

        digitalWrite(this->triggerPin, HIGH);
        delayMicroseconds(this->triggerTime);
        digitalWrite(this->triggerPin, LOW);

        unsigned long newDuration = pulseIn(this->echoPin, HIGH, this->timeOut);

        if (newDuration != 0)
        {
            duration = newDuration;
        }
    }

    return duration;
}

float MC_M_HCSR04::distance()
{
    return distance(true);
}

float MC_M_HCSR04::distance(boolean system)
{
    if (system)
    {
        // CM
        return pulseDuration() / 58.2751;
    }
    else
    {
        // INCH
        return pulseDuration() / 148.0187;
    }
}