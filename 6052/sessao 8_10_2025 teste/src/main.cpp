#include <Arduino.h>
//configurar os botoes
typedef struct botao
{
  int periferico;
  int estado;
};
botao botao_cima;
botao botao_direita;
botao botao_baixo;
botao botao_esquerda;

int opcao=0;
//configurar as portas serie
void setup()
{
 Serial.begin(9600);

 botao_cima.periferico= 4;
 botao_direita.periferico=5;
 botao_baixo.periferico=6;
 botao_esquerda.periferico=7;

 pinMode(botao_cima.periferico,INPUT);
 pinMode(botao_direita.periferico,INPUT);
 pinMode(botao_baixo.periferico,INPUT);
 pinMode(botao_esquerda.periferico,INPUT);
}

void loop() 
{
 botao_cima.estado = !digitalRead(botao_cima.periferico);
 botao_direita.estado =!digitalRead(botao_direita.periferico);
 botao_baixo.estado = !digitalRead(botao_baixo.periferico);
 botao_esquerda.estado = !digitalRead(botao_esquerda.periferico);
 

//nenhum dos botoes pressionados
if (!botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=0;
}
//botao de cima pressionado
if (botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=1;
}
//botao da direita pressionado 
if (!botao_cima.estado && botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=2;
}
//botao de baixo pressionado
if (!botao_cima.estado && !botao_direita.estado && botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=3;
}
//botao da esquerda pressionado
if (!botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && botao_esquerda.estado)
{
  opcao=4;
}
//botao de cima e da direita pressionados
if (botao_cima.estado && botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=5;
}
//botao da direita e baixo pressionados
if (!botao_cima.estado && botao_direita.estado && botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=6;
}
//botao de cima e da esquerda pressionados
if (botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && botao_esquerda.estado)
{
  opcao=7;
}
//botao de baixo e esquerda pressionados
if (!botao_cima.estado && !botao_direita.estado && botao_baixo.estado && botao_esquerda.estado)
{
  opcao=8;
}
 switch (opcao)
 {

 case 0:
  Serial.println("no setas");
  break;

 case 1:
  Serial.println("⬆");
  break;

 case 2:
  Serial.println("→");
  break;

 case 3:
  Serial.println("↓");
  break;

 case 4:
  Serial.println("←");
  break;
 
  case 5:
  Serial.println("↗");
  break;

 case 6:
  Serial.println("↘");
  break;

 case 7:
  Serial.println("↖");
  break;

 case 8:
  Serial.println("↙");
  break;

 default:
  Serial.println("erro");
  break;
 }
 delay(500);
}




