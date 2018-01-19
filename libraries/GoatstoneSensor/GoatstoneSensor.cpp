#include "Arduino.h"
#include "GoatstoneSensor.h"
#include <string>

GoatstoneSensor::GoatstoneSensor(int pin)
{
  _pin = pin;
  // char snum[5];
  int sensorPin = A0;    // select the input pin for the potentiometer
  int sensorValue = 0;  // variable to store the value coming from the sensor  
}
int GoatstoneSensor::get()
{
  int sensorValue = analogRead(sensorPin);
  return sensorValue;
}
