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

rele reles[3];

void setup() 
{
 Serial.begin(9600);
 reles[1].periferico=7;
 reles[2].periferico=8;
 reles[3].periferico=9;

 pinMode(reles[1].periferico,OUTPUT);
 pinMode(reles[2].periferico,OUTPUT);
 pinMode(reles[3].periferico,OUTPUT);


 reles[1].temporizador.tempo_anterior=millis();
 reles[2].temporizador.tempo_anterior=millis();
 reles[3].temporizador.tempo_anterior=millis();


 reles[1].temporizador.intervalo=5000;
 reles[2].temporizador.intervalo=10000;
 reles[3].temporizador.intervalo=15000;


}
//ligar rele com temporizador de 5 segundos
void loop() 
{
  //temporizador
  if (millis()-reles[1].temporizador.tempo_anterior>reles[1].temporizador.intervalo)
  {
    //executar uma açao
    Serial.println("Executar");
  
  //ligar e desligar 
   if (digitalRead(reles[1].periferico))
  {
    //desligar rele
   digitalWrite(reles[1].periferico,LOW);
   Serial.println("desliga rele1");
  }
   else
  {
    //ligar rele
   digitalWrite(reles[1].periferico,HIGH);
   Serial.println("liga rele1");
  }
  //atualizar
  reles[1].temporizador.tempo_anterior=millis();
}
 if (millis()-reles[2].temporizador.tempo_anterior>reles[2].temporizador.intervalo)
  {
    //executar uma açao
    Serial.println("Executar");
  
  //ligar e desligar 
   if (digitalRead(reles[2].periferico))
  {
    //desligar rele
   digitalWrite(reles[2].periferico,LOW);
   Serial.println("desliga rele2");
  }
   else
  {
    //ligar rele
   digitalWrite(reles[2].periferico,HIGH);
   Serial.println("liga rele2");
  }
  //atualizar
  reles[2].temporizador.tempo_anterior=millis();
}
if (millis()-reles[3].temporizador.tempo_anterior>reles[3].temporizador.intervalo)
  {
    //executar uma açao
    Serial.println("Executar");
  
  //ligar e desligar 
   if (digitalRead(reles[3].periferico))
  {
    //desligar rele
   digitalWrite(reles[3].periferico,LOW);
   Serial.println("desliga rele3");
  }
   else
  {
    //ligar rele
   digitalWrite(reles[3].periferico,HIGH);
   Serial.println("liga rele3");
  }
  //atualizar
  reles[3].temporizador.tempo_anterior=millis();
}
}