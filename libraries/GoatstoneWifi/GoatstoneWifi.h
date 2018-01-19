#ifndef GoatstoneWifi_h
#define GoatstoneWifi_h
#include <ESP8266WiFi.h>

#include "Arduino.h"

class GoatstoneWifi
{
  public:
    GoatstoneWifi(int pin);
    WiFiClient client;
    void init();
    int ping();
  private:
    int _pin;
};

#endif