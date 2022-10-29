#define LED 8

void setup (void) {
  pinMode (LED, OUTPUT);
}

void loop (void) {
  digitalWrite (LED, HIGH);

  delay (1000);

  digitalWrite (LED, LOW);

  delay (1000);
}
