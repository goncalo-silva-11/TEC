#include <Arduino.h>

unsigned int tempo_atual= 0;
unsigned int tempo_atual2= 0;

unsigned int tempo_anterior=0;
unsigned int tempo_anterior2=0;


int periferico=4;
int periferico2=5;

void setup() 
{
 Serial.begin(9600);
 pinMode(periferico,OUTPUT);
 pinMode(periferico2,OUTPUT);
}
void loop() 
{
  tempo_atual=millis();
  
  if (tempo_atual - tempo_anterior > 1000)
  {
    Serial.print("tempo_atual - ");   
    Serial.println(tempo_atual);
    
    Serial.print("tempo_anterior - ");
    Serial.println(tempo_anterior);
    //piscar led
    if (digitalRead(periferico)==LOW)
    {
      digitalWrite(periferico, HIGH);
    }
    else
    {
      digitalWrite(periferico,LOW);
    }
    tempo_anterior=millis();
  }
  tempo_atual2=millis();

  if (tempo_atual2 - tempo_anterior2 > 2000)
  {  
    //piscar led
    if (digitalRead(periferico2)==LOW)
    {
      digitalWrite(periferico2, HIGH);
    }
    else
    {
      digitalWrite(periferico2,LOW);
    }
     tempo_anterior2=millis();
  }  
}

