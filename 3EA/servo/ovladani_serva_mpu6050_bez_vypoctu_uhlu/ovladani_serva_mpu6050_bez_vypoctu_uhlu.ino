#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo;
Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  myservo.attach(9);
  mpu.begin();
  delay(100);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print(a.acceleration.z);
  Serial.println();
  myservo.write(90+90*a.acceleration.x/20.0);
  delay(5);
}