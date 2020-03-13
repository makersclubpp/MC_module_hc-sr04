/**
 * 
 * \file MC_module_hcsr04.c
 * \brief
 *  
 */

#include "Arduino.h"
#include "MC_module_hcsr04.hpp"

HCSR04::HCSR04(int triggerPin, int echoPin)
{
    HCSR04(triggerPin, echoPin, timeOut);
}

HCSR04::HCSR04(int triggerPin, int echoPin, long timeOut)
{
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->timeOut = timeOut;

    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

long HCSR04::pulseDuration()
{
    digitalWrite(this->triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->triggerPin, LOW);

    long duration = pulseIn(this->echoPin, HIGH, this->timeOut);

    if (duration == 0)
    {
        duration = timeOut;
    }

    return duration;
}

float HCSR04::distance()
{
    return distance(true);
}

float HCSR04::distance(boolean system)
{
    if (system)
    {
        // CM
        return pulseDuration() / 58.2;
    }
    else
    {
        // INCH
        return pulseDuration() / 148;
    }
}