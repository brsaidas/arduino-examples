#define Led 10
#define Potenciometro A3

int ValorAnalogico = 0;

void setup(){
  Serial.begin(9600);  
  pinMode(Led, OUTPUT);
}

void loop(){
  ValorAnalogico = analogRead(Potenciometro);

  analogWrite(Led, ValorAnalogico/4);
  delay(50);
  
  Serial.print("VA = ");
  Serial.print(ValorAnalogico);
  Serial.print(" | VL = ");
  Serial.println(ValorAnalogico/4);
}
