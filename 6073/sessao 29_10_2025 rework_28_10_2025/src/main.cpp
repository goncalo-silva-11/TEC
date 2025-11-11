#include <Arduino.h>
int opcao=0;
int estado=0;
typedef enum eLed
{
  CIMA_L=0,
  DIREITA_L,
  BAIXO_L,
  ESQUERDA_L,
  TOTAL_L
};

typedef enum eBotao
{
  CIMA_B=0,
  DIREITA_B,
  BAIXO_B,
  ESQUERDA_B,
  TOTAL_B
};
 int index=0;
 
typedef struct Led
{
  int estado;
  int periferico;
};
Led leds[TOTAL_L];


typedef struct Botao
{
  int estado;
  int periferico;
};
Botao botoes[TOTAL_B];

typedef enum OPCAO
{
  FAZER_NADA=0,
  CIMA =1,
  DIREITA =2,
  BAIXO=4,
  ESQUERDA=8,
  TODOS=16,
};
OPCAO opcoes=FAZER_NADA;

void ledsi(int cima, int direita, int baixo, int esquerda)
{
  digitalWrite(leds[0].periferico , cima);
  digitalWrite(leds[1].periferico , direita);
  digitalWrite(leds[2].periferico , baixo);
  digitalWrite(leds[3].periferico , esquerda);
}

void setup()
{
 Serial.begin(9600);

 leds[CIMA_L].periferico=8;
 leds[DIREITA_L].periferico=9;
 leds[BAIXO_L].periferico=10;
 leds[ESQUERDA_L].periferico=11;

 
 botoes[CIMA_B].periferico=2;
 botoes[DIREITA_B].periferico=3;
 botoes[BAIXO_B].periferico=4;
 botoes[ESQUERDA_B].periferico=5;
 
 index = 0;
 while (index < TOTAL_B)
 {
  botoes[index].estado==LOW;
  leds [index].estado==LOW;
   pinMode(botoes[index].periferico, INPUT);
   pinMode(leds[index].periferico, OUTPUT);
  index++;
 }
 
}

void loop() 
{
  
  index=0;
  opcao= 0; 
  //ler botao
  //testar botao
  while (index < TOTAL_B) 
  {
    botoes[index].estado= !digitalRead(botoes[index].periferico);
    index++;
    Serial.print(botoes[index].estado);
  }
    Serial.println("hh");

  if (botoes[CIMA_B].estado)          
  {
    opcao= opcao+ 1;
  }

  if (botoes[DIREITA_B].estado)
  {
    opcao=opcao +2;
  }

  if (botoes[BAIXO_B].estado)
  {
    opcao=opcao +4;
  }

  if (botoes[ESQUERDA_B].estado)
  {
    opcao=opcao +8;
  }

  switch (opcao)
  {
  case FAZER_NADA:
    ledsi(LOW,LOW,LOW,LOW);
  Serial.println("nenhum led ligado");
    break;
  
  case CIMA:
    ledsi(HIGH,LOW,LOW,LOW);
  Serial.println("LIGA CIMA");
    break;

  case DIREITA:
    ledsi(LOW,HIGH,LOW,LOW);
  Serial.println("LIGA DIREITA");
    break;

  case BAIXO:
    ledsi(LOW,LOW,HIGH,LOW);
  Serial.println("LIGA BAIXO");
    break;

  case ESQUERDA:
    ledsi(LOW,LOW,LOW,HIGH);
  Serial.println("LIGA ESQUERDA");
    break;

  case CIMA + DIREITA:
    ledsi(HIGH,HIGH,LOW,LOW);
  Serial.println("LIGA CIMA_DIREITA");
    break;

  case CIMA + BAIXO:
    ledsi(HIGH,LOW,HIGH,LOW);
  Serial.println("LIGA CIMA_BAIXO");
    break;

  case CIMA + ESQUERDA:
    ledsi(HIGH,LOW,LOW,HIGH);
  Serial.println("LIGA CIMA_ESQUERDA");
    break;

  case BAIXO + DIREITA:
    ledsi(LOW,HIGH,HIGH,LOW);
  Serial.println("LIGA BAIXO_DIREITA");
    break;

  case BAIXO + ESQUERDA:
    ledsi(LOW,LOW,HIGH,HIGH);
  Serial.println("LIGA BAIXO_ESQUERDA");
    break;

  case DIREITA + ESQUERDA:
    ledsi(LOW,HIGH,LOW,HIGH);
  Serial.println("LIGA DIREITA_ESQUERDA");
    break;

  case CIMA + DIREITA + BAIXO:
    ledsi(HIGH,HIGH,HIGH,LOW);
  Serial.println("LIGA CIMA_DIREITA_BAIXO");
    break;

  case CIMA + DIREITA + ESQUERDA:
    ledsi(HIGH,HIGH,LOW,HIGH);
  Serial.println("LIGA CIMA_DIREITA_ESQUERDA");
    break;
    
    case CIMA + BAIXO + ESQUERDA:
      ledsi(HIGH,LOW,HIGH,HIGH);
    Serial.println("LIGA CIMA_BAIXO_ESQUERDA");
      break;

  case BAIXO + DIREITA + ESQUERDA:
    ledsi(LOW,HIGH,HIGH,HIGH);
  Serial.println("LIGA BAIXO_DIREITA_ESQUERDA");
    break;

  case TODOS:
    ledsi(HIGH,HIGH,HIGH,HIGH);
  Serial.println("TODOS LIGAODS");
    break;


  default:
  Serial.println("erro");
    break;
  }
  delay(100);
}



//para testar botao:
//int estado=0;
//void setup()

//serial.begin(9600)
//pinMode(2,INPUT)

//void loop()
//estado=!digitalRead (2)
//Serial.println(estado)
//delay(500)
