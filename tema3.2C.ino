xTaskCreate(mi_tarea, // Nombre de la función tarea
		"EJEMPLO",  // Texto de referencia de la tarea	
		10000, 	  // Memoria asignada a la tarea
		NULL, 	  // Parámetros de entrada de la tarea
		0, 		  // Prioridad
		NULL);	  // Manejador
