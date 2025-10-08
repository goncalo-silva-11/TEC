#include <Arduino.h>
// int led_esquerda=3;
// int led_direita =4;
// int botao_esquerda=10;
// int botao_direita=12;
// int estado_do_botao_direita=0;
// int estado_do_botao_esquerda=0;
// int opcao=0;
// int estado_do_led_direito=0;
// int estado_do_led_esquerdo=0;
 typedef struct botao
 {
  int periferico;
  int estado;
 };

 botao botao_direita;
 botao botao_esquerda;

 typedef struct Leds
 {
  int periferico;
 };

 Leds leds_direita;
 Leds leds_esquerda;

 int opcao=0;

void setup() 
{

  botao_direita.periferico=12;
  botao_esquerda.periferico=10;

  leds_direita.periferico=4;
  leds_esquerda.periferico=3;

  pinMode(botao_direita.periferico,INPUT);
  pinMode(botao_esquerda.periferico,INPUT);

  pinMode(leds_direita.periferico,OUTPUT);
  pinMode(leds_esquerda.periferico,OUTPUT);
  Serial.begin(9600);
}

void leds(int estado_led_direita, int estado_led_esquerda,String message)
{
  digitalWrite(leds_direita.periferico,botao_direita.estado);
  digitalWrite(leds_esquerda.periferico,botao_esquerda.estado);
  Serial.println(message);
  
  // void leds(int estado_do_led_direito, int estado_do_led_esquerdo, String message)
  // {
  //   digitalWrite(led_esquerda,estado_do_botao_esquerda);
  //   digitalWrite(led_direita,estado_do_botao_direita);
  //   Serial.println(message);
}

void loop() 
{
  botao_direita.estado=!digitalRead(botao_direita.periferico);
  botao_esquerda.estado=!digitalRead(botao_esquerda.periferico);

// void loop() 
// {
  // estado_do_botao_direita= digitalRead(botao_direita)==LOW;
  // estado_do_botao_esquerda= digitalRead(botao_esquerda)==LOW;


  if (!botao_direita.estado && !botao_esquerda.estado)
  {
    opcao=0;
  }
  if (botao_direita.estado && !botao_esquerda.estado)
  {
    opcao=1;
  }
  if (!botao_direita.estado && botao_esquerda.estado)
  {
    opcao=2;
  }
  if (!botao_direita.estado && !botao_esquerda.estado)
  {
    opcao=3;
  }
  
  // if (!estado_do_botao_direita && !estado_do_botao_esquerda)
  // // desligar leds
  // {
  //   opcao=0;
  // }
  // if (estado_do_botao_direita && !estado_do_botao_esquerda)
  // //ligar led da direita e desligar o led da esquerda
  // {
  //   opcao=1;
  // }
  // if (!estado_do_botao_direita && estado_do_botao_esquerda)
  // //desligar led da direita e ligar led da esquerda
  // {
  //   opcao=2;
  // }
  // if (estado_do_botao_direita && estado_do_botao_esquerda)
  // //ligar led da direita e ligar led da esquerda
  // {
  //   opcao=3;
  // }

switch (opcao)
{
case 0:
 leds(LOW, LOW,"ambos os leds desligados");
  break;

case 1:
 leds(HIGH,LOW,"led da direita ligado");
 break;

case 2:
 leds(LOW,HIGH,"led da esquerda ligado");
 break;

case 3:
 leds(HIGH,HIGH,"ambos os leds ligados");

default:
 Serial.println("leds desligados");
 break;
}
 delay(500);
}

  //  switch (opcao)
  //  {
  //  case 0:
  //  //ambos os leds desligados
  //   leds(LOW, LOW,"ambos os leds desligados");
  //   break;
  //  case 1:
  //  //ligar led da direita e desligar o led da esquerda
  //   leds(HIGH,LOW,"led da direita ligado");
  //  break;
  //  case 2:
  //  //ligar led da esquerda e desligar o led da direita
  //  leds(LOW, HIGH,"led da esquerda ligado");
  //  break;
  //  case 3:
  //  //ligar ambos os leds
  //  leds(HIGH,HIGH,"ambos os leds ligados");
  //  break;
  //  default:
  //  Serial.println("leds desligados");
  //   break;
  //  }
  //  delay(500);
  // }
  
  
