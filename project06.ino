#define Led 13

char Letra = '\0';
String Entrada = "";

void setup(){
  Serial.begin(9600);

  pinMode(Led, OUTPUT);
}

void loop(){  
  while(Serial.available() > 0){
    Serial.print(" -> SA = ");
    Serial.println(Serial.available());
    
    Letra = (char) Serial.read();

    if(Letra != '\n'){
      Entrada += Letra;
    }
    delay(5);
  }

  Serial.print("Entrada = ");
  Serial.print("[");
  Serial.print(Entrada);
  Serial.println("]");

  if(Entrada == "Ligado"){
    Entrada = "";
    digitalWrite(Led, HIGH);  
  }else if(Entrada == "Desligado"){
    Entrada = "";
    digitalWrite(Led, LOW);  
  }else{
    Entrada = "";
  }
}
