#include <Arduino.h>
#define numero_de_botoes 3
#define numero_de_reles 3

typedef struct rele
{
  int periferico;
  int estado;
};

rele reles[numero_de_reles];

typedef struct botao
{
  int periferico;
  int estado;
};

botao botoes[numero_de_botoes];
//variavel de ajuda
int contar=0;

void setup() 
{
  Serial.begin(9600);
  //configurar botoes
  botoes[0].periferico=2;
  botoes[1].periferico=3;
  botoes[2].periferico=4;
  //configurar reles
   reles[0].periferico=5;
   reles[1].periferico=6;
   reles[2].periferico=7;
 //inicializar index
 contar=0;
 //enquanto houver botoes, inicializar o perifierico como entrada
 while (contar<numero_de_botoes)
 {
   botoes[contar].estado=0;
   pinMode(botoes[contar].periferico, INPUT);
   
   reles[contar].estado=0;
   pinMode(reles[contar].periferico, OUTPUT);
  //incrementar index
  contar++;
 }
}

void loop() 
{
  contar=0;
  while (contar<numero_de_botoes)
  {
    //leiruta do botao
    botoes[contar].estado=!digitalRead(botoes[contar].periferico);
    //se botao a HIGH , Rele HIGH
   if (botoes[contar].estado)
   {
     Serial.println("botao pressionado");
     reles[contar].estado=HIGH;
     digitalWrite(reles[contar].periferico,reles[contar].estado);
     Serial.println("rele ativado");
   }
    else
   {
     Serial.println("botao nao pressionado");
     reles[contar].estado=LOW;
     digitalWrite(reles[contar].periferico,reles[contar].estado);
     Serial.println("rele desativado");
   }
   contar++;
  }
 }
 