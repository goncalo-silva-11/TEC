#include <Arduino.h>

//enumerar botoes
typedef enum eBotoes
{
  NENHUM_B=0,
  CIMA_B,
  DIREITA_B,
  BAIXO_B,
  ESQUERDA_B,
  TOTAL_B
};
//enumerar leds
typedef enum eLED
{
  NENHUM_L=0,
  CIMA_L,
  DIREITA_L,
  BAIXO_L,
  ESQUERDA_L,
  TOTAL_L
};

//configurar botoes
int index=0;
typedef struct Botao
{
  int estado;
  int periferico;
};
Botao botao[TOTAL_B];
//enumerar leds
typedef struct LED
{
  int estado;
  int periferico;
};
LED Leds[TOTAL_L];

typedef enum Opcao
{
//nao ligar
  FAZER_NADA=0,
//ligar 1
  LIGAR_CIMA,
  LIGAR_DIREITA,
  LIGAR_BAIXO,
  LIGAR_ESQUERDA,
//ligar 2
  LIGAR_CIMA_DIREITA,
  LIGAR_CIMA_ESQUERDA,
  LIGAR_BAIXO_DIREITA,
  LIGAR_BAIXO_ESQUERDA,
  LIGAR_DIREITA_ESQUERDA,
  LIGAR_CIMA_BAIXO,
//ligar 3
  LIGAR_CIMA_DIREITA_ESQUERDA,
  LIGAR_CIMA_DIREITA_BAIXO,
  LIGAR_CIMA_ESQUERDA_BAIXO,
  LIGAR_BAIXO_DIREITA_ESQUERDA,
//ligar todos
  LIGAR_TODOS
}; 
Opcao opcao = FAZER_NADA;
//funçao para acender os leds
void leds(int cima, int direita, int baixo, int esquerda)
{
  digitalWrite(Leds[0].periferico , cima);
  digitalWrite(Leds[1].periferico , direita);
  digitalWrite(Leds[2].periferico , baixo);
  digitalWrite(Leds[3].periferico , esquerda);

}

void setup()
{
 Serial.begin(9600);
//enquanto indice for menor que 4
 while (index < 4)
 {
   botao[index].estado = LOW;
 }
  pinMode(index, INPUT);
  pinMode(index, OUTPUT);

  index++;
//configurar perifericos led
 Leds[0].periferico =3; //led cima
 Leds[1].periferico =4; //led direita
 Leds[2].periferico =5; //led baixo
 Leds[3].periferico =6; //led esquerda
//configurar perifericos botoes
 botao[0].periferico = 7; //botao cima
 botao[1].periferico = 8; //botao direita
 botao[2].periferico = 9; //botao baixo
 botao[3].periferico = 10; //botao esquerda

}

void loop() 
{
  //leitura dos botoes
  //enquanto indice for maior que 4
 index=0;
 while (index<4)
 {
   botao[index].estado = !digitalRead(botao[index].periferico);//leitura botao de cima
   index++;
 }
 
 if (!botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  FAZER_NADA;
 }
 if (botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA;
 }
 if (!botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_DIREITA;
 }
 if (!botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_BAIXO;
 }
 if (!botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_ESQUERDA;
 }
 if (botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA_DIREITA;
 }
 if (botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA_ESQUERDA;
 }
 if (botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA_BAIXO;
 }
  if (!botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_DIREITA_ESQUERDA;
 }
  if (!botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_BAIXO_DIREITA;
 }
  if (!botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_BAIXO_ESQUERDA;
 }
  if (botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     !botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA_DIREITA_BAIXO;
 }
  if (botao[CIMA_B].estado && 
     !botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA_ESQUERDA_BAIXO;
 }
  if (botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     !botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_CIMA_DIREITA_ESQUERDA;
 }
  if (!botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_BAIXO_DIREITA_ESQUERDA;
 }
  if ( botao[CIMA_B].estado && 
     botao[DIREITA_B].estado &&
     botao[BAIXO_B].estado &&
     botao[ESQUERDA_B].estado)
 {
  LIGAR_TODOS;
 }

 //definir opçao
 FAZER_NADA;

 //definir switch cases
 switch (FAZER_NADA)
 {
 case FAZER_NADA:
  leds(LOW,LOW,LOW,LOW);
  Serial.println("nenhum led ligado");
  break;

  case LIGAR_CIMA:
  leds(HIGH,LOW,LOW,LOW);
  Serial.println("led CIMA LIGADO");
  break;

  case LIGAR_DIREITA:
  leds(LOW,HIGH,LOW,LOW);
  Serial.println("led DIREITA LIGADO");
  break;

  case LIGAR_BAIXO:
  leds(LOW,LOW,HIGH,LOW);
  Serial.println("led BAIXO LIGADO");
  break;

  case LIGAR_ESQUERDA:
  leds(LOW,LOW,LOW,HIGH);
  Serial.println("led ESQUERDA LIGADO");
  break;

  case LIGAR_CIMA_DIREITA:
  leds(HIGH,HIGH,LOW,LOW);
  Serial.println("led CIMA E DIREITA LIGADOS");
  break;

  case LIGAR_CIMA_ESQUERDA:
  leds(HIGH,LOW,LOW,HIGH);
  Serial.println("led CIMA E ESQUERDA LIGADOS");
  break;

  case LIGAR_CIMA_BAIXO:
  leds(HIGH,LOW,HIGH,LOW);
  Serial.println("led CIMA E BAIXO LIGADOS");
  break;

  case LIGAR_BAIXO_DIREITA:
  leds(LOW,HIGH,HIGH,LOW);
  Serial.println("led BAIXO E DIREITA LIGADOS");
  break;

  case LIGAR_BAIXO_ESQUERDA:
  leds(LOW,LOW,HIGH,HIGH);
  Serial.println("led BAIXO E ESQUERDA LIGADOS");
  break;

  case LIGAR_DIREITA_ESQUERDA:
  leds(LOW,HIGH,LOW,HIGH);
  Serial.println("led DIREITA E ESQUERDA LIGADOS");
  break;

  case LIGAR_CIMA_DIREITA_BAIXO:
  leds(HIGH,HIGH,HIGH,LOW);
  Serial.println("led CIMA DIREITA E BAIXO LIGADOS");
  break;

  case LIGAR_CIMA_ESQUERDA_BAIXO:
  leds(HIGH,LOW,HIGH,HIGH);
  Serial.println("led CIMA ESQUERDA E BAIXO LIGADOS");
  break;

  case LIGAR_CIMA_DIREITA_ESQUERDA:
  leds(HIGH,HIGH,LOW,HIGH);
  Serial.println("led CIMA DIREITA E ESQUERDA LIGADOS");
  break;

  case LIGAR_BAIXO_DIREITA_ESQUERDA:
  leds(LOW,HIGH,HIGH,HIGH);
  Serial.println("led BAIXO DIREITA E ESQUERDA LIGADOS");
  break;

  case LIGAR_TODOS:
  leds(HIGH,HIGH,HIGH,HIGH);
  Serial.println("TODOS LEDS LIGADOS");
  break;
 }
 delay(500);
}