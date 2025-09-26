#include <Arduino.h>
const int pinbotao=12;
const int pinLED=3;
const int BAUD_RATE= 9600;
void setup() 
{
  pinMode(pinbotao,INPUT);
  pinMode(pinLED,OUTPUT);
  Serial.begin(BAUD_RATE);
}

void loop() 
{
  //escrever no monitor a leitura do botao
  Serial.println(digitalRead(pinbotao));
  //Quando carregar no botao
    //ler botao
    if (digitalRead(pinbotao)==LOW)
    {
       //Ligar LED
     digitalWrite(pinLED,HIGH);
     Serial.println("led ligou");
     
    }
    else
    {
      //desligar o led
      digitalWrite(pinLED,LOW);
      Serial.println("led desligou");
    }
    delay(1000);
}