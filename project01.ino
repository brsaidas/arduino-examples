char LedVermelho = 10;
char LedVerde = 6;

int FaseVerde = 0;
int EstadoVerde = 0;
int TempoVerde = 0;
int ContadorVerde = 0;

int FaseVermelho = 0;
int EstadoVermelho = 0;
int TempoVermelho = 1000;
int ContadorVermelho = 0;

void setup() {
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedVerde, OUTPUT);
}

void loop() {
  if(ContadorVermelho*50 == TempoVermelho){
    if(EstadoVermelho == 0){
      EstadoVermelho = 1;
      digitalWrite(LedVermelho, HIGH);
    }else{
      EstadoVermelho = 0;
      digitalWrite(LedVermelho, LOW);
    }

    if(FaseVermelho == 0){
      TempoVermelho -= 50;
      if(TempoVermelho == 50){
        FaseVermelho = 1;  
      }
    }else{
      TempoVermelho += 50;
      if(TempoVermelho == 1000){
        FaseVermelho = 0;
      }
    }
    
    ContadorVermelho = 0;
  }

  if(ContadorVerde*50 == TempoVerde){
    if(EstadoVerde == 0){
      EstadoVerde = 1;
      digitalWrite(LedVerde, HIGH);
    }else{
      EstadoVerde = 0;
      digitalWrite(LedVerde, LOW);
    }

    if(FaseVerde == 0){
      TempoVerde -= 50;
      if(TempoVerde == 50){
        FaseVerde = 1;  
      }
    }else{
      TempoVerde += 50;
      if(TempoVerde == 1000){
        FaseVerde = 0;
      }
    }
    
    ContadorVerde = 0;
  }
  
  delay(50);
  ContadorVerde++;
  ContadorVermelho++;
}
