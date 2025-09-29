#include <Arduino.h>
int botao_direita=3;
int botao_esquerda=4;
void setup() 
{
 Serial.begin(9600);
 pinMode(botao_direita,INPUT);
 pinMode(botao_esquerda,INPUT);
}
void loop() 
{
  while (digitalRead(botao_direita)==LOW)
  {
    Serial.println("anda para a direita");
  }
  while (digitalRead(botao_esquerda)==LOW)
  {
    Serial.println("anda para a esquerda");
  }
  delay(500);
}