#define I2C_SDA0_PIN 4
#define I2C_SCL0_PIN 5

#define NUM_ADC_READINGS 25
#define ACCEL_READING_INTERVAL 50

void mpu6050_init() {
  Wire.begin(I2C_SDA0_PIN, I2C_SCL0_PIN, 400000);
  mpu6050.begin();

  Serial.printf("Comenzando calibración...");
  mpu6050.calcGyroOffsets(true);
  Serial.printf("Listo!\n");

  mpu6050.update();
}

void task_mpu6050_get_accel_data(void *pvParameters) {
  float accel_readings[3];

  while (1) {
      mpu6050.update();
      accel_readings[0] = mpu6050.getGyroX();
      accel_readings[1] = mpu6050.getGyroY();
      accel_readings[2] = mpu6050.getGyroZ();
      delay(1);
    }
    delay(ACCEL_READING_INTERVAL);
  }
  vTaskDelete(NULL);
}

