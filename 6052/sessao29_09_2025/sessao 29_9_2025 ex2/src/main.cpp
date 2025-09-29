#include <Arduino.h>
int botao=3;


void setup() 
{
 Serial.begin(9600);
 pinMode(botao,INPUT); 
}

void loop() 
{
  while (digitalRead(botao)==LOW)
  {
    Serial.println("+1");
  }
  delay(500);

}