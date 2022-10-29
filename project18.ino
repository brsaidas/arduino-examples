#define PINO_MOTOR 8

void setup() {
  pinMode(PINO_MOTOR, OUTPUT);
}

void loop() {
  digitalWrite(PINO_MOTOR, HIGH);
  delay(5000);

  digitalWrite(PINO_MOTOR, LOW);
  delay(5000);
}
