#include <Arduino.h>
unsigned int tempo_atual= 0;
unsigned int tempo_anterior=0;
int comecar_contagem=0;
int led=2;
int botao=4;

void setup() 
{
 Serial.begin(9600);
 pinMode(led,OUTPUT);
 pinMode(botao,INPUT);
 digitalWrite(led,LOW);
}
void loop() 
{
//botao a ser pressionado começa a contagem
  if (digitalRead(botao)==LOW)
  {
    comecar_contagem=1;
    tempo_anterior=millis();
    Serial.println("botao pressionado");
  }

  
  if (comecar_contagem)
  {
    if (millis()-tempo_anterior >5000)
    {
      digitalWrite(led,HIGH);
      Serial.println("led liga");
      tempo_anterior=millis();   
    }
    }
  }


