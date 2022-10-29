#define ENTRADA1 4
#define ENTRADA2 7
#define ENTRADA3 2
#define ENTRADA4 8
#define HABILITA1 5
#define HABILITA2 3

void setup(void) {
  pinMode(ENTRADA1, OUTPUT);
  pinMode(ENTRADA2, OUTPUT);
  pinMode(ENTRADA3, OUTPUT);
  pinMode(ENTRADA4, OUTPUT);
  pinMode(HABILITA1, OUTPUT);
  pinMode(HABILITA2, OUTPUT);
}

void loop(void) {
  digitalWrite(ENTRADA1, LOW);
  digitalWrite(ENTRADA2, HIGH);
  analogWrite(HABILITA1, 255);

  digitalWrite(ENTRADA3, LOW);
  digitalWrite(ENTRADA4, HIGH);
  analogWrite(HABILITA2, 255);
}
