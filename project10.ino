#define PinoControle 10
#define PinoInterrupcao 2

int Contador = 0;
char Letra = '\0';

void setup(){
  Serial.begin(9600);
  
  pinMode(PinoControle, OUTPUT);
  pinMode(PinoInterrupcao, INPUT);

  attachInterrupt(digitalPinToInterrupt(PinoInterrupcao), Interrupcao, CHANGE);
}

void loop(){
  while(Serial.available() > 0){
    Letra = (char) Serial.read();

    if(Letra == 'a'){
      digitalWrite(PinoControle, !digitalRead(PinoControle));
    }
  }
}

void Interrupcao(){
  Serial.println(++Contador);
}
