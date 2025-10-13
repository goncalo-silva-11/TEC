#include <Arduino.h>
//configurar temporizador
typedef struct Temporizador
{
  unsigned long tempo_anterior;
  unsigned long intervalo;
};
//configurar rele
typedef struct rele
{
  int estado;
  int periferico;

  Temporizador temporizador;
};

rele rele1;
rele rele2;

void setup() 
{
 Serial.begin(9600);
 rele1.periferico=4;
 rele2.periferico=7;
 pinMode(rele1.periferico,OUTPUT);
 pinMode(rele2.periferico,OUTPUT);

 rele1.temporizador.tempo_anterior=millis();
 rele2.temporizador.tempo_anterior=millis();

 rele1.temporizador.intervalo=5000;
 rele2.temporizador.intervalo=10000;

}
//ligar rele com temporizador de 5 segundos
void loop() 
{
  //temporizador
  if (millis()-rele1.temporizador.tempo_anterior>rele1.temporizador.intervalo)
  {
    //executar uma açao
    Serial.println("Executar");
  
  //ligar e desligar 
   if (digitalRead(rele1.periferico))
  {
    //desligar rele
   digitalWrite(rele1.periferico,LOW);
   Serial.println("desliga rele");
  }
   else
  {
    //ligar rele
   digitalWrite(rele1.periferico,HIGH);
   Serial.println("liga rele");
  }
  //atualizar
  rele1.temporizador.tempo_anterior=millis();
}
 if (millis()-rele2.temporizador.tempo_anterior>rele2.temporizador.intervalo)
  {
    //executar uma açao
    Serial.println("Executar");
  
  //ligar e desligar 
   if (digitalRead(rele2.periferico))
  {
    //desligar rele
   digitalWrite(rele2.periferico,LOW);
   Serial.println("desliga rele");
  }
   else
  {
    //ligar rele
   digitalWrite(rele2.periferico,HIGH);
   Serial.println("liga rele");
  }
  //atualizar
  rele2.temporizador.tempo_anterior=millis();
}
}