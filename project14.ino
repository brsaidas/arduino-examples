#include <Ultrasonic.h>

#define trig 11
#define echo 10

bool controle = false;

Ultrasonic ultrassonico(trig, echo);

void setup(){
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
    String entrada = "";

    if(Serial.available() > 0){
      while(Serial.available() > 0){
        char letra = (char) Serial.read();
  
        if(letra != '\n'){
          entrada += letra;
        }
        delay(10);
      }

      if(entrada == "on"){
        controle = true;
      }else if(entrada == "off"){
        controle = false;
      }

      Serial.print("entrada: [");
      Serial.print(entrada);
      Serial.println("]");
    }

    if(controle == true){
      Serial.print(ultrassonico.Ranging(CM));
      Serial.println(" cm");
      delay(100);
    }
}
