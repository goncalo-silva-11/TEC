#include <Arduino.h>
//configurar perifericos
int led_esquerda=3;
int led_direita =4;
int botao_esquerda=10;
int botao_direita=12;
int estado_do_botao_direita=0;
int estado_do_botao_esquerda=0;
int opcao=0;
int estado_do_led_direito=0;
int estado_do_led_esquerdo=0;

void leds(int estado_do_led_direito, int estado_do_led_esquerdo, String message)
{
  digitalWrite(led_esquerda,estado_do_botao_esquerda);
  digitalWrite(led_direita,estado_do_botao_direita);
  Serial.println(message);
}
void setup() 
{
 Serial.begin(9600);
 pinMode(led_direita,OUTPUT);
 pinMode(led_esquerda,OUTPUT);
 pinMode(botao_direita,INPUT);
 pinMode(botao_esquerda,INPUT);
}

void loop() 
{
  //leitura dos botoes
  estado_do_botao_direita= digitalRead(botao_direita)==LOW;
  estado_do_botao_esquerda= digitalRead(botao_esquerda)==LOW;

  //quando os botoes nao estiverem pressionados,
  if (!estado_do_botao_direita && !estado_do_botao_esquerda)
  // desligar leds
  {
    opcao=0;
  }
  //quando o botao da direita estiver pressionado e o botao da esquerda nao estiver pressionado
  if (estado_do_botao_direita && !estado_do_botao_esquerda)
  //ligar led da direita e desligar o led da esquerda
  {
    opcao=1;
  }
  //quando o botao da direita nao estiver pressionado e o botao da esquerda estiver pressionado
  if (!estado_do_botao_direita && estado_do_botao_esquerda)
  //desligar led da direita e ligar led da esquerda
  {
    opcao=2;
  }
  //quando o botao da direita estiver pressionado e o botao da esquerda estiver pressionado
  if (estado_do_botao_direita && estado_do_botao_esquerda)
  //ligar led da direita e ligar led da esquerda
  {
    opcao=3;
  }
   switch (opcao)
   {
   case 0:
   //ambos os leds desligados
    leds(LOW, LOW,"ambos os leds desligados");
    break;
   case 1:
   //ligar led da direita e desligar o led da esquerda
    leds(HIGH,LOW,"led da direita ligado");
   break;
   case 2:
   //ligar led da esquerda e desligar o led da direita
   leds(LOW, HIGH,"led da esquerda ligado");
   break;
   case 3:
   //ligar ambos os leds
   leds(HIGH,HIGH,"ambos os leds ligados");
   break;
   default:
   Serial.println("leds desligados");
    break;
   }
   delay(500);
  }
  
  
  

  
