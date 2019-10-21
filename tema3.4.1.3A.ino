void setup() {
  uint8_t variable1=17;
  Serial.begin(115200);
  Serial.printf("Valor: %d y reside en: 0x%X\n", variable1, &variable1);
}

void loop() { delay(1000); }
