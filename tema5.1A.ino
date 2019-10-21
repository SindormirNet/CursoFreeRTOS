
En la zona global
----------------------------------

QueueHandle_t cola;
uint8_t tam_cola = 10;

En el setup()
----------------------------------

cola = xQueueCreate(tam_cola, sizeof (uint8_t));

xTaskCreatePinnedToCore(task_cons, "CONS", 6048, NULL, 10, &cons_handle, 1);
xTaskCreatePinnedToCore(task_prod, "PROD", 6048, NULL, 15, &prod_handle, 1);

Funciones de las tareas
----------------------------------

void task_prod(void * pvParameters) {
  uint16_t contador = 0;
  
  while (true) {
    if (digitalRead(PULS_A)==HIGH) {
      xQueueSend(cola, &contador, portMAX_DELAY);
      Serial.printf("Soy PRODUCTOR: He metido en la cola: [%d]\n", contador);
      contador++;
      delay(500); //Damos tiempo a soltar el pulsador
    }
    delay(50);
  }
}

void task_cons(void * pvParameters) {
  uint8_t elemento;
  
  while (true) {
    xQueueReceive(cola, &elemento, portMAX_DELAY);
    Serial.printf("Soy CONSUMIDOR: He recibido de la cola: [%d]\n", elemento);
  }
}
