elimina_tarea(&handler_task_a); //Llamada a la función

void elimina_tarea(TaskHandle_t *manejador) { //Implementación
  
  if (*manejador != NULL) {
    vTaskDelete(*manejador);
    *manejador = NULL;
  }
}
