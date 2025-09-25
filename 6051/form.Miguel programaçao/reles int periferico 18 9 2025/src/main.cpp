#include <Arduino.h>

int aura = 9;
int aura2=10;
int botao= 6;
void setup()

{
  pinMode(aura, OUTPUT);
  pinMode(aura2, OUTPUT);
  pinMode(botao, INPUT);
}
void loop()
{
  if (digitalRead(botao)==HIGH)
 { 
   delay(500);
 }
  else(digitalRead(botao)==LOW);
  { 
   delay(2000);
  }
  digitalWrite(aura, HIGH);
  digitalWrite(aura2, HIGH);
  
  delay(1000);
  digitalWrite(aura, LOW);
  digitalWrite(aura2, LOW);
  
  delay(1000);
}

