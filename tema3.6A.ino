void elimina_tarea(){
  if (handler_task_a != NULL){
    Serial.printf("Eliminando tarea\n");
    vTaskDelete(handler_task_a);
    handler_task_a = NULL;
  }
  else{
    Serial.printf("No elimino tarea porque ya no existía\n");
  }
}
