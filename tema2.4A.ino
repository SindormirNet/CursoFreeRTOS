#define PULSADOR_A 26
#define PULSADOR_B 25
#define LED_ROJO 18
#define LED_VERDE 19

void setup() {
  Serial.begin(115200);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(PULSADOR_A, INPUT_PULLUP);
  pinMode(PULSADOR_B, INPUT_PULLUP);
}

void loop() {
  static unsigned long tiempo = 0;
  if ((millis() - tiempo >= 500) && digitalRead(PULSADOR_B) == HIGH) {
    digitalWrite(LED_ROJO, !digitalRead(LED_ROJO));
    tiempo = millis();
  }
  digitalWrite(LED_VERDE, !digitalRead(PULSADOR_A));
}
