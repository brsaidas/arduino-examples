#include <TimerOne.h>

#define LED 13

void setup(){
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(TimerInterrupcao);

  digitalWrite(LED, HIGH);
}

void loop(){
  
}

void TimerInterrupcao(){
  Serial.print("Tempo: ");
  Serial.println(millis());
  digitalWrite(LED, !digitalRead(LED));  
}
