TaskHandle_t handler_task_a;

void setup() { 
  Serial.begin(115200);
 xTaskCreate(task_a, "TAREA_A", configMINIMAL_STACK_SIZE + 2000, NULL, 0, &handler_task_a);  
}

void loop() { delay(1000); }

void task_a(void * pvParameters) {
  Serial.printf("Creando tarea para Tarea A\n");

  while (true) {
    Serial.printf("[TAREA A]\n");
    delay(1000);
  }
  vTaskDelete(NULL);
}
