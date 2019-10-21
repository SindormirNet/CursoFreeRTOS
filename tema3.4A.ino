void setup() {
  Serial.begin(115200);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  tareas_init();
}

void loop() { delay(1000); }

void tareas_init() {
  static uint8_t led1 = 18;
  static uint8_t led2 = 19;
  xTaskCreate(task_led, "L1", 2000, (void*) &led1, 0, NULL);
  delay(333); //Desfasamos la segunda tarea de la primera
  xTaskCreate(task_led, "L2", 2000, (void*) &led2, 1, NULL);
}

void task_led(void * pvParameters) {
  uint8_t ledpin = *((uint8_t *)pvParameters);

  Serial.printf("Creando tarea para LED: %d\n", ledpin);

  while (true) {
    Serial.printf("[LED %d]\n", ledpin);
    digitalWrite(ledpin, HIGH);
    delay(333);
    digitalWrite(ledpin, LOW);
    delay(333);
  }
  vTaskDelete(NULL);
}
