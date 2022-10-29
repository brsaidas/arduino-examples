char Led = 6;
char Botao = 10;
bool Estado = false;
char Contador = 0;
int Tempo = 1000;
bool Fase = false;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(Botao, INPUT);
}

void loop() {
  
  if(digitalRead(Botao)){
      if(Fase == false){
        Tempo -= 50;
        if(Tempo == 50){
          Fase = !Fase;
        }
      }else{
        Tempo += 50;
        if(Tempo == 1000){
          Fase = !Fase;
        }
      }

      Contador = 0;
      
      while(digitalRead(Botao));
  }

  if(Contador*50 == Tempo){
    Estado = !Estado;
    digitalWrite(Led, Estado);

    Contador = 0;
  }

  delay(50);
  Contador++;
}
