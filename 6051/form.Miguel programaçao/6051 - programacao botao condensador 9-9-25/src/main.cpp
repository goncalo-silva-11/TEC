#include <Arduino.h>
void setup()
{pinMode (10, INPUT);
pinMode (13, OUTPUT);
}
void loop()
{
  if (digitalRead(10)==HIGH)
  {
    digitalWrite(10, HIGH);
    }
    else
    {
      digitalWrite(10, LOW);
      }
      delay(50);
}
