#include <Arduino.h>
int botao_esquerda=10;
int botao_direita=12;
int led_esquerda=3;
int led_direita=4;
int estado_do_botao_esquerdo=0;
int estado_do_botao_direito=0;
int opcao=0;

void leds(int estado_do_led1, int estado_do_led2 , String message)
{
    Serial.println(message);
    digitalWrite(led_esquerda,estado_do_led1);
    digitalWrite(led_direita,estado_do_led2);
} 

// void leds_desligam()
// {
//     Serial.println("ambos os leds desligam");
//     digitalWrite(led_direita,LOW);
//     digitalWrite(led_esquerda,LOW);
// }
// void led_da_direita_liga()
// {
//     Serial.println("led da direita liga");
//     digitalWrite(led_direita,HIGH);
//     digitalWrite(led_esquerda,LOW);
// }
// void led_da_esquerda_liga()
// {
//     Serial.println("led da esquerda liga");
//     digitalWrite(led_esquerda,HIGH);
//     digitalWrite(led_direita,LOW);
// }
// void leds_ligam()
// {
//     Serial.println("ambos leds ligam");
//     digitalWrite(led_direita,HIGH);
//     digitalWrite(led_esquerda,HIGH);
// }


void setup() 
{
 pinMode(botao_esquerda,INPUT);
 pinMode(botao_direita,INPUT);
 pinMode(led_esquerda,OUTPUT);
 pinMode(led_direita,OUTPUT);
 Serial.begin(9600);
}

void loop() 
{
 estado_do_botao_direito= digitalRead(botao_direita)==LOW;
 estado_do_botao_esquerdo=digitalRead(botao_esquerda)==LOW;


 if (!estado_do_botao_direito&&!estado_do_botao_esquerdo)
 {
  opcao=0;
 }
 if (!estado_do_botao_direito && estado_do_botao_esquerdo)
 {
  opcao=1;
 }
 if (estado_do_botao_direito && !estado_do_botao_esquerdo)

 {
  opcao=2;
 }
 if (estado_do_botao_direito && estado_do_botao_esquerdo)
 {
  opcao=3;
 }
//  switch (opcao)
//  {
//  case 0:
//     leds_desligam();
//     break;
// case 1:
//     led_da_direita_liga();
//     break;
// case 2:
//     led_da_esquerda_liga();
//     break;
// case 3:
//     leds_ligam();
//     break;
 
//  default:
//     Serial.println("erro");
//     break;
//  }
//  delay(500);
// }
 switch (opcao)
 {
 case 0:
    leds(LOW,LOW,"desligados");
    break;
case 1:
    leds(HIGH,LOW,"led da esquerda liga");
    break;
case 2:
    leds(LOW,HIGH,"led da direita liga");
    break;
case 3:
    leds(HIGH,HIGH,"ligados");
    break;
 
 default:
    Serial.println("erro");
    break;
 }
 delay(500);
}

