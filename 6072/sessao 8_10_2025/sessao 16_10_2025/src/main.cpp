#include <Arduino.h>

//configurar botoes
typedef struct botao
{
  int estado;
  int periferico;
};

botao botoes[3];
//configurar reles
typedef struct rele
{
  int estado;
  int periferico;
};

rele reles[3];

void setup() 
{
 Serial.begin(9600);
//configurar portas serie
 reles[0].periferico=3;
 reles[1].periferico=4;
 reles[2].periferico=5;

 pinMode(reles[0].periferico,OUTPUT);
 pinMode(reles[1].periferico,OUTPUT);
 pinMode(reles[2].periferico,OUTPUT);

 botoes[0].periferico=7;
 botoes[1].periferico=8;
 botoes[2].periferico=9;

 pinMode(botoes[0].periferico,INPUT);
 pinMode(botoes[1].periferico,INPUT);
 pinMode(botoes[2].periferico,INPUT);
}

void loop() 
{
 
  botoes[0].estado=!digitalRead(7);
  Serial.println(botoes[0].estado);

  //testar se o botao esta pressionado
  if (botoes[0].estado)
  {
    Serial.println("botao pressionado");
    reles[0].estado=digitalRead(3);
    //se o rele esta ligado
    if (reles[0].estado)
    {
      //desligar
      digitalWrite(reles[0].periferico,LOW);
      Serial.println("rele 0 ativado");
    }
    //senao
    else
    {
      //ligar
      digitalWrite(reles[0].periferico,HIGH);
      Serial.println("rele 0 desativado");
    }
  }
  else
  {
   Serial.println("botao nao pressionado");
  }
  delay(500);
    

  }

  


