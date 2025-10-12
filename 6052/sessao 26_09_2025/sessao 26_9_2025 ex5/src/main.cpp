#include <Arduino.h>
int temperatura_lida=5;
int temperatura_maxima=20;
int temperatura_minima=3;
int botao=2;
int led=10;
int botao_de_arranque_1=1;
int botao_de_arranque_2=0;
int sobrecarga=7;


void setup() 
{
  Serial.begin(9600);
  
}

void loop() 
{
  if (digitalRead(botao)==LOW)
  {
    digitalWrite(led,HIGH);
    Serial.println("led ligado");
    Serial.println("botao pressionado");
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println("led desligado");
    Serial.println("botao nao pressionado");
  }
  
  if (temperatura_lida >= temperatura_maxima)
  {
    Serial.println("ligar ventoinha");
  }
  else
  {
    Serial.println("desligar ventoinha");
  }
  if (temperatura_lida <= temperatura_minima)
  {
    Serial.println("ligar esquentador");
  }
  else
  {
    Serial.println("desligar esquentador");
  }
  if (botao_de_arranque_1&&botao_de_arranque_2)
  {
    Serial.println("ligar maquina");
  }
  else
  {
    Serial.println("desligar maquina");
  } 
  if ((temperatura_lida > temperatura_maxima) || sobrecarga) //quando a temp lida for maior que a temp max ou acontece uma sobrecarga..
  {
    Serial.println("desligar maquina");
  }
  else
  {
    Serial.println("continuar ligada");
  }

  delay(4000);
}

