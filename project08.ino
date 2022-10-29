#define PinoInterrupcao 2

int Contador = 0;

void setup(){  
  Serial.begin(9600);
  pinMode(PinoInterrupcao, INPUT);

  attachInterrupt(digitalPinToInterrupt(PinoInterrupcao), Interrupcao, FALLING);
}

void loop(){
  
}

void Interrupcao(){
  Serial.println(Contador++);
}
