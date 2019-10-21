#define SONDA_A 21
#define SONDA_B 22

void setup() {
  Serial.begin(115200);
  pinMode(SONDA_A, OUTPUT);
  pinMode(SONDA_B, OUTPUT);
  digitalWrite(SONDA_B, HIGH);
}

void loop() {
  static unsigned long tiempo = 0;

  if (millis() - tiempo >= 5) {
    digitalWrite(SONDA_A, !digitalRead(SONDA_A));
    digitalWrite(SONDA_B, !digitalRead(SONDA_B));
    tiempo = millis();
  }
}
