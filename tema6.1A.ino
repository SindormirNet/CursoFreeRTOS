TimerHandle_t handle_timer;

void setup() {
  Serial.begin(115200);

  handle_timer = xTimerCreate( 
				"Disparo único", // Nombre temporizador
                    pdMS_TO_TICKS(3000), // Carga del tiempo
                    pdFALSE, // pdFALSE == disparo único
                    0,  // Identificador del temporizador
                    timer_test_disparo_unico); // Callback

  if ( handle_timer != NULL ) xTimerStart( handle_timer, 0 );

}

void timer_test_disparo_unico(TimerHandle_t tiempo) {
  Serial.printf( "Ejecutando callback en: %d\n", millis());
}

void loop() {
  Serial.printf("El tiempo es: %d\n", millis());
  delay(1000);
}
