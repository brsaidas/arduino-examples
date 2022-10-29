#include <SoftwareSerial.h>

int inicio = -1;
String entrada = "", bloco = "";

SoftwareSerial bluetooth(2, 3);

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);  
}

void loop(){
  if(bluetooth.available() > 0){    
    while(bluetooth.available() > 0){
      char letra = bluetooth.read();
     
      entrada += letra;

      switch(letra){
        case '{':
          if(inicio != -1){
            entrada = "{";  
          }
        
          inicio = entrada.length() - 1;
          break;
        case '}':
          if(inicio != -1){
            bloco = entrada.substring(inicio + 1, entrada.length() - 1);

            bluetooth.print("{");
            bluetooth.print(bloco);
            bluetooth.print("}");

            Serial.print("Recebido: [");
            Serial.print(bloco);
            Serial.println("]");

            inicio = -1;
          }

          entrada = "";
          break;
        default:
          break;
      }
      
      delay(10);
    }
  }
}
