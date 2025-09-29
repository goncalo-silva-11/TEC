#include <Arduino.h>
int teste = 0;//1//10
void setup() 
{
  pinMode(teste,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if (teste)
  {
    Serial.println("Verdadeiro");
  
  }
  else
  {
    Serial.println("Falso");
  }
  delay(1000);
}


