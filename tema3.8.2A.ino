xTaskCreate(task_serial_low, "SERIAL_LOW", 6048, NULL, 2, &serial_low_handle);
xTaskCreate(task_serial_hi, "SERIAL_HI", 6048, NULL, 3, &serial_hi_handle);

 void task_serial_hi(void * pvParameters) {
     unsigned int counter=0;
     while (true) {
         Serial.printf("[SERIAL HI] [%d] [%d] Ejecutándome...\n", millis(), counter++);
     }
 }   
 void task_serial_low(void * pvParameters) {
     unsigned int counter=0;
     while (true) {
         Serial.printf("[SERIAL LO] [%d] [%d] Ejecutándome...\n", millis(), counter++);
     }   
 }
