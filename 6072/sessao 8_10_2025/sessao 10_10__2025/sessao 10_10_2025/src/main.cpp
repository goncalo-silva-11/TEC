#include <Arduino.h>
//variaveis
typedef struct sensor_temperatura
{
  int valor;
  int periferico;
  unsigned long tempo_anterior;
  unsigned long intervalo;
};
 sensor_temperatura sensor1;
 sensor_temperatura sensor2;
 sensor_temperatura sensor3;
void setup() 
{
  Serial.begin(9600);
  sensor1.tempo_anterior=millis();
  sensor2.tempo_anterior=millis();
  sensor3.tempo_anterior=millis();

  sensor1.intervalo=1000;
  sensor2.intervalo=2000;
  sensor3.intervalo=5000;
}

void loop() 
{
  if (millis()-sensor1.tempo_anterior>sensor1.intervalo)
  {
    Serial.println("+1000 aura");
    sensor1.tempo_anterior=millis();
  } 
  if (millis()-sensor2.tempo_anterior>sensor2.intervalo)
  {
    Serial.println("-100 aura");
    sensor2.tempo_anterior=millis();
  }
  if (millis()-sensor3.tempo_anterior>sensor3.intervalo)
  {
    Serial.println("infinite aura");
    sensor3.tempo_anterior=millis();
 }
}