#define Led 10
#define Botao 2
#define Eixo_X A0
#define Eixo_Y A1

void setup(){
  pinMode(Led, OUTPUT);
  pinMode(Botao, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop(){
  analogWrite(Led, ((1023 - analogRead(Eixo_X))/4));

  delay(50);
}
