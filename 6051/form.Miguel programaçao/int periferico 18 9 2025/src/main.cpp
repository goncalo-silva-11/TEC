#include <Arduino.h>

int periferico = 11;
void setup()
{
  pinMode(periferico, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop()
{
  digitalWrite(periferico, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(periferico, LOW);
  digitalWrite(7, LOW);
  delay(1000);
}