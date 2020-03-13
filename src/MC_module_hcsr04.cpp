/**
 * 
 * \file MC_module_hcsr04.c
 * \brief
 *  
 */

#include "Arduino.h"
#include "MC_module_hcsr04.hpp"

HCSR04::HCSR04(int tp, int ep)
{
    HCSR04(tp, ep, timeOut);
}

HCSR04::HCSR04(int tp, int ep, long to)
{
    pinMode(tp, OUTPUT);
    pinMode(ep, INPUT);
    triggerPin = tp;
    echoPin = ep;
    timeOut = to;
}

long HCSR04::pulseDuration()
{
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH, timeOut);

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