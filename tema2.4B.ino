void loop_control_led_rojo() {
  if (digitalRead(PULSADOR_B) == HIGH){
    digitalWrite(LED_ROJO, !digitalRead(LED_ROJO));
    delay(500);
  }
}

void loop_control_led_verde() {
  digitalWrite(LED_VERDE, !digitalRead(PULSADOR_A));
}
