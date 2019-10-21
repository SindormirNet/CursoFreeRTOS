uint32_t dame_hora() {
  uint32_t milisegundos;
  TickType_t ahora;
  ahora = xTaskGetTickCount();
  milisegundos = (ahora * 1000) / configTICK_RATE_HZ;
  return milisegundos;
}
