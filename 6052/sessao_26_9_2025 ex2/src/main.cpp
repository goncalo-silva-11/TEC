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
  //Quando carregar no botao
  Serial.println(digitalRead(pinbotao));
    //quando o botao estiver a ser pressionado
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