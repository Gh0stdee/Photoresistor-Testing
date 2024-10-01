#include <Arduino.h>
#define photoSignalPin 4  

bool bootState = false;               //set default state of ESP32 to be off

void setup() {
Serial.begin(9600);                   //set serial monitor communication speed
pinMode(photoSignalPin, INPUT);       //set photoresistor signal pin to be input 


}

void loop() {
  int light = analogRead(photoSignalPin);       //store the signal pin into light variable
  int lightLevel = map(light, 0,4095,0,15);     //map the analog values into 16 values (lightlevel is 15 when light is 4095)
  Serial.println(light);                        //print the light value onto serial monitor
  
  //check if ESP32 needs to be turned on 
  if (lightLevel > 11 && !bootState)
  {
    Serial.println("Turning on...");
    bootState = true;
  }
  else if (lightLevel <= 11 && bootState)
  {
    Serial.println("Turning off...");
    bootState = false;
  }
  delay(1000);
}
