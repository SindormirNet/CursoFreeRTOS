TaskHandle_t handle_led;

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  xTaskCreate(task_led, "LED1", 2000, NULL, 0, &handle_led);
}

void loop() {
  delay(3000);
  xTaskNotifyGive(handle_led);
}

void task_led(void * pvParameters) {
  unsigned long notify_msg;

  while (true) {
    notify_msg = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    if (notify_msg != NULL ) {
      Serial.printf("[L %d] -> %d\n", millis(), notify_msg);
      digitalWrite(13, HIGH);
      delay(300);
      digitalWrite(13, LOW);
      delay(300);
    }
  }
  vTaskDelete(NULL);
}
