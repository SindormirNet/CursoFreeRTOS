xTaskCreate(task_recursiva, "RECURSIVA", configMINIMAL_STACK_SIZE+200, NULL, 3, NULL);

void task_recursiva(void * pvParameters){
     static int veces;
     while(1){
         Serial.printf("Ejecutado %d veces\n", veces++);
         task_recursiva(NULL); 
     }
     vTaskDelete(NULL);
}  
