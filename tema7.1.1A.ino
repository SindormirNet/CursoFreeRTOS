#define PULSADOR 0

SemaphoreHandle_t semaforo;

void setup() {
  Serial.begin(115200);
  pinMode(PULSADOR, INPUT_PULLUP);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);

  semaforo = xSemaphoreCreateBinary();

  xTaskCreate(task_A, "TAREA A", 2000, NULL, 0, NULL);

  attachInterrupt(PULSADOR, pulsador_ISR, FALLING);

}

void pulsador_ISR() {
  xSemaphoreGiveFromISR(semaforo, NULL); 
}

void loop() { delay(1000); }

void task_A(void * pvParameters) {

  while (true) {
    xSemaphoreTake(semaforo, portMAX_DELAY);
    Serial.printf("TAREA A: ME HAN PULSADO\n");

    delay(100);
  }
  vTaskDelete(NULL);

}
