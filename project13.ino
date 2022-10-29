#include <SoftwareSerial.h>

#define Led1 8
#define Led2 9
#define Led3 10

String mensagem;

SoftwareSerial Bluetooth(2, 3);

void setup(){
  Serial.begin(9600);
  Bluetooth.begin(9600);   

  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
}

void loop(){
  mensagem = "";

  if(Bluetooth.available() > 0){
    while(Bluetooth.available() > 0){
      char letra = Bluetooth.read();

      if(letra != '\n'){
        mensagem.concat(letra);
      }
      delay(10);
    }

    Serial.print("Msg: [");
    Serial.print(mensagem);
    Serial.println("]");

    if(mensagem.indexOf("Led1") > -1){
      digitalWrite(Led1, !digitalRead(Led1));
    }

    if(mensagem.indexOf("Led2") > -1){
      digitalWrite(Led2, !digitalRead(Led2));  
    }

    if(mensagem.indexOf("Led3") > -1){
      digitalWrite(Led3, !digitalRead(Led3));
    }

    Bluetooth.print("{");

    if(digitalRead(Led1) == HIGH){
      Bluetooth.print("l1on");
    }else{
      Bluetooth.print("l1of");  
    }

    if(digitalRead(Led2) == HIGH){
      Bluetooth.print("l2on");
    }else{
      Bluetooth.print("l2of");
    }

    if(digitalRead(Led3) == HIGH){
      Bluetooth.print("l3on");  
    }else{
      Bluetooth.print("l3of");  
    }

    Bluetooth.print("}");
  }
}
