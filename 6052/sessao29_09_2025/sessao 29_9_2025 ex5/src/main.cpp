#include <Arduino.h>
int botao_direito=12;
int botao_esquerdo=10;
int led_direito=4;
int led_esquerdo=3;
int opcao=4;
void setup() 
{
  Serial.begin(9600);
  pinMode(botao_direito,INPUT);
  pinMode(botao_esquerdo,INPUT);
  pinMode(led_direito,OUTPUT);
  pinMode(led_esquerdo,OUTPUT);
}

void loop() 
{
  if (digitalRead(botao_esquerdo)==LOW)
  {
    opcao=1;
  }
  
  if (digitalRead(botao_direito)==LOW)
  {
    opcao=3;
  }
  
  if (digitalRead(botao_esquerdo)==LOW && digitalRead(botao_direito)==LOW)
  {
    opcao=2;
  }
  if (digitalRead(botao_direito)==HIGH && digitalRead(botao_esquerdo)==HIGH)
  {
    opcao=4;
  }
  
  switch (opcao)
  {
  case 1:
    Serial.println("led da esquerda liga");
    digitalWrite(led_esquerdo,HIGH);
    digitalWrite(led_direito,LOW);
    break;
  case 2:
      Serial.println("ambos leds ligam");
      digitalWrite(led_esquerdo,HIGH);
      digitalWrite(led_direito,HIGH);
      break;
  case 3:
    Serial.println("led da direita liga");
    digitalWrite(led_direito,HIGH);
    digitalWrite(led_esquerdo,LOW);
    break;
  case 4:
    Serial.println("leds desligados");
    digitalWrite(led_direito,LOW);
    digitalWrite(led_esquerdo,LOW);
    break;
  default:
    Serial.println("opcao nao existe");
    break;
  }
delay(500);

}