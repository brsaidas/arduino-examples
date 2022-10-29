#define PinoLed 10
#define PinoInterrupcao 2

int Contador = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(PinoLed, OUTPUT);
  pinMode(PinoInterrupcao, INPUT);

  attachInterrupt(digitalPinToInterrupt(PinoInterrupcao), Interrupcao, FALLING);

  digitalWrite(PinoLed, HIGH);
}

void loop(){
  
}

void Interrupcao(){
  Serial.println(++Contador);
  digitalWrite(PinoLed, !digitalRead(PinoLed));
}
