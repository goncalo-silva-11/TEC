#include <Arduino.h>

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
 if (digitalRead(12)==HIGH)
 {
   digitalWrite(2,HIGH);
 }
 else
 {
   digitalWrite(2,LOW);
 }
  delay(50);
}