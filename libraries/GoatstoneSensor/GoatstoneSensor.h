#ifndef GoatstoneSensor_h
#define GoatstoneSensor_h

#include "Arduino.h"
#include <string>

class GoatstoneSensor
{
  public:
    GoatstoneSensor(int pin);
    int get(); // temp light sound motion
    int sensorPin;    // select the input pin for the potentiometer
    int sensorValue;  // variable to store the value coming from the sensor
  private:
    int _pin;
};

#endif