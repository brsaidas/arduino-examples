#define Led 6
#define Botao 10

unsigned char Contador = 255;

void setup(){
  pinMode(Led, OUTPUT);
  pinMode(Botao, INPUT);  
}

void loop(){
  while(digitalRead(Botao)){
    analogWrite(Led, Contador);
  
    delay(10);
    if(Contador < 255) Contador++;
  }
  
  analogWrite(Led, Contador);

  delay(10);
  if(Contador > 0) Contador--;
}
