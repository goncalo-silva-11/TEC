#include <Arduino.h>
int botao=3;
int led=5;


void setup() 
{
 Serial.begin(9600);
 pinMode(botao, INPUT);
 pinMode(led, OUTPUT);
}

void loop() 
{ //enquanto o botao estiver a ser pressionado
while (digitalRead(botao)==LOW)
{
 digitalWrite(led,HIGH);
 Serial.println("led ligado");
 delay(500);
}
digitalWrite(led,LOW);
Serial.println("led desligado");
delay(500);

}