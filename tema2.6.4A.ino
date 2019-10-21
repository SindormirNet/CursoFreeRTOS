#define VAL_MAX 1000
#define VAL_MAX_RUN 1000
xTaskHandle handle_task_of;

void setup() {
  Serial.begin(115200);
  xTaskCreate(task_overflow, "OVERFLOW", 5000, NULL, 1, &handle_task_of);
}

void loop() { delay(1000); }

void task_overflow(void *pvParameters) {
  int i = 1;
  volatile float valor;
  int prueba[VAL_MAX];
  while (1) {
    prueba[i] = (prueba[i - 1] + 1) * 2;
    if (prueba[i] > 65536) {
      prueba[i] = 0;
    }
    Serial.printf("%d %d\n", i, prueba[i]);

    if (i == VAL_MAX_RUN) {
      i = 0;
    }
    else {
      i++;
    }
    delay(1);
  }
  vTaskDelete(NULL);
}
