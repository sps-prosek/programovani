#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  mpu.begin();
  delay(100);
}

void loop() {
  static float x_filtr;
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // filtrace
  float x = a.acceleration.x;
  x_filtr = 0.1*x + 0.9*x_filtr;

  Serial.print(x);
  Serial.print(",");
  Serial.print(x_filtr);
  Serial.println();
  delay(50);
}