void setup() {
  uint8_t variable1=17;
  uint8_t *puntero=0;

  Serial.begin(115200);

  puntero = &variable1;

  Serial.printf("Valor: %d y reside en: 0x%X\n", variable1, &variable1);
  Serial.printf("Puntero a: 0x%X. Contenido: %d\n", puntero, *puntero);  
}
void loop() { delay(1000); }
