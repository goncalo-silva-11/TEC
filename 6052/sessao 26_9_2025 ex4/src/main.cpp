#include <Arduino.h>
int led=2;
int botao=10;

void setup() 
{
 Serial.begin(9600);
 pinMode(botao, INPUT);
 pinMode(led, OUTPUT);
}

void loop() 
{
 if (digitalRead(botao)== LOW)
 {
  digitalWrite(led,HIGH);
  Serial.println("botao pressionado");
 }
 else
 {
  digitalWrite(led,LOW);
  Serial.println("botao nao pressionado");
 }
 delay(500);
}

