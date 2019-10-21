#define LED_PINA 18
#define TAM_STACK ????

TaskHandle_t task_led_handle;

void setup() {
  Serial.begin(115200);
  Serial.printf("Arrancando\n");
  pinMode(LED_PINA, OUTPUT);
  xTaskCreate(task_led1, "LED1", TAM_STACK, NULL, 0, &task_led_handle);
}

void loop() { delay(1000); }

void task_led_handle(void * pvParameters) {
  while (true) {
      Serial.printf("[LED1]\n");
      digitalWrite(LED_PINA, HIGH);
      delay(500);
      digitalWrite(LED_PINA, LOW);
      delay(500);
  }
  vTaskDelete(NULL);
}
