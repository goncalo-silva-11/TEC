#include <Arduino.h>
int opcao=0;

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  switch (opcao)
  {
  case 0:
    Serial.println("temperatura normal");
    break;

  case 1:
    Serial.println("temperatura alta");
    break;

  case 2:
    Serial.println("temperatura baixa");
    break;

  case 3:
    Serial.println("temperatura acima dos 25ºC");
    break;

  default:
    Serial.println("opcao nao existe");
    break;
  }
}