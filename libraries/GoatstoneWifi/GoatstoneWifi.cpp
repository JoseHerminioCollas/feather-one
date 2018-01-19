#include "Arduino.h"
#include "GoatstoneWifi.h"
#include <ESP8266WiFi.h>

GoatstoneWifi::GoatstoneWifi(int pin)
{
  WiFiClient client;
  _pin = pin;
}
int GoatstoneWifi::ping()
{
  return 1;
}
void GoatstoneWifi::init()
{
  #define WIFI_SSID       "onetwothree"
  #define WIFI_PASS       "gby7u6Iq8uv2x4"
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected IP address:");  
  Serial.println(WiFi.localIP());  
  Serial.println("Wifi");  
}
