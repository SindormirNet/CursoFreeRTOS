char ptrTaskList[1024];
void task_print_usage(){
     vTaskList(ptrTaskList);
     Serial.printf("**********************************\n");
     Serial.printf("Task  State  Prio  Stack  Num  Core\n");
     Serial.printf("**********************************\n");
     Serial.printf(ptrTaskList);
     Serial.printf("**********************************\n");
 }
