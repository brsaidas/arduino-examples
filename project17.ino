#include <SoftwareSerial.h>

#define RX 2
#define TX 3
#define LED_VERMELHO 11
#define LED_AMARELO 10
#define LED_VERDE 9

SoftwareSerial Bluetooth(RX, TX);

void setup(void) {
  Serial.begin(9600);
  Bluetooth.begin(9600);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  Serial.println("INICIO");
}

void loop(void) {  
  if (Bluetooth.available() > 0) {   
    byte recebido = Bluetooth.read();
    int intencidade = 3*recebido;

    Serial.print(recebido, DEC);
    Serial.print(" | ");
    Serial.print(intencidade);
    Serial.print(" | ");    

    if (intencidade > 255) {
      analogWrite(LED_VERDE, 255);
      Serial.print(255);
      Serial.print(" | ");
    } else if (intencidade < 0) {
      analogWrite(LED_VERDE, 0);
      Serial.print(0);
      Serial.print(" | ");
    } else {
      analogWrite(LED_VERDE, intencidade);
      Serial.print(intencidade);
      Serial.print(" | ");
    }

    if (intencidade > 510) {
      analogWrite(LED_AMARELO, 255);
      Serial.print(255);
      Serial.print(" | ");
    } else if (intencidade < 256) {
      analogWrite(LED_AMARELO, 0);
      Serial.print(0);
      Serial.print(" | ");
    } else {
      analogWrite(LED_AMARELO, intencidade - 255);
      Serial.print(intencidade - 255);
      Serial.print(" | ");
    }

    if (intencidade > 765) {
      analogWrite(LED_VERMELHO, 255);
      Serial.print(255);
    } else if (intencidade < 511) {
      analogWrite(LED_VERMELHO, 0);
      Serial.print(0);
    } else {
      analogWrite(LED_VERMELHO, intencidade - 510);
      Serial.print(intencidade - 510);
    }

    Serial.print("\n");
  }
}
