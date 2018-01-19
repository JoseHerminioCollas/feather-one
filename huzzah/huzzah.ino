#include <GoatstoneSensor.h>
#include <GoatstoneWifi.h>
#include "config.h"
#include <PubSubClient.h>

GoatstoneWifi gWifi(1);
GoatstoneSensor gs(A0);
PubSubClient mqttClient(gWifi.client);
unsigned long previousMillis = 0;
const long interval = 3000;
char snum[5];

int count = 0;
int ledState = LOW;

void setup() {
  Serial.begin(115200);
  delay(100);
  gWifi.init(); 
    mqttClient.setServer("192.168.0.10", 1883);   
    if (mqttClient.connect("myClientID")) {
      Serial.println("mqtt success");
      mqttClient.subscribe("albatros");      
      mqttClient.subscribe("albatros:light-on");      
      mqttClient.subscribe("albatros:light-off");      
      mqttClient.setCallback(callback);
    } else {
      // connection failed
      Serial.println("mqttClient.state()");
      Serial.println(mqttClient.state());
  }    
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
}
void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println(gs.get());  
    boolean rct = mqttClient.publish("temp", itoa(gs.get(), snum, 10) );  
  }
  count++;
  mqttClient.loop();
  digitalWrite(14, ledState);
  analogWrite(12, count % 200 );  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  delay(100);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  if (strcmp(topic, "albatros") == 0) {
    Serial.print("AAAA ");    
  }
  if (strcmp(topic, "albatros:light-on") == 0) {
    Serial.print("turn on ");    
    ledState = HIGH;
  }
  if (strcmp(topic, "albatros:light-off") == 0) {
    Serial.print("turn off ");    
    ledState = LOW;
  }
}


