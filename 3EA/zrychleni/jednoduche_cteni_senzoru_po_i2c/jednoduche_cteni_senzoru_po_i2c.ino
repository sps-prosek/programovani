#include <Wire.h>

#define MPU_ADDRESS 0x68
#define REGISTER    0x75

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(REGISTER);
  Wire.endTransmission();

  Wire.requestFrom(MPU_ADDRESS, 1);

  if (Wire.available()) {
    byte data = Wire.read();
    Serial.println(data, HEX);
  }

  delay(1000);
}
