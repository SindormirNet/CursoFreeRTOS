char letras[10];

void setup() {
  Serial.begin(115200);
  xTaskCreate(task_A, "TA", 2000, NULL, 0, NULL);
  xTaskCreate(task_B, "TB", 2000, NULL, 0, NULL);
}

void loop() {  delay(1000); }

void task_A(void * pvParameters) {
  while (true) {
      for (int i = 0; i < 10; i++) {
        letras[i] = 'A';       
        delay(10);
      }
      letras[9] = '\0';
      
      Serial.printf("Tarea A: %s\n", letras);
  }
  vTaskDelete(NULL);
}


void task_B(void * pvParameters) {
  while (true) {
      for (int i = 0; i < 10; i++) {
        letras[i] = 'B';
        delay(10);
      }
      letras[9] = '\0';
      
      Serial.printf("Tarea B: %s\n", letras);
  }

  vTaskDelete(NULL);
}
