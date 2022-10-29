#include "Servo.h"

#define PinoBotao 6
#define PinoServo 10

Servo servo;

bool Fase = true;
unsigned char Giro = 0;

void setup(){  
  servo.attach(PinoServo);
  pinMode(PinoBotao, INPUT);

  servo.write(0);
  delay(5);
}

void loop(){
  if(digitalRead(PinoBotao)){
      Fase ? Giro += 15 : Giro -= 15;

      if(Giro % 180 == 0) Fase = !Fase;

      while(digitalRead(PinoBotao));
  }

  servo.write(Giro);
  delay(5);
}
