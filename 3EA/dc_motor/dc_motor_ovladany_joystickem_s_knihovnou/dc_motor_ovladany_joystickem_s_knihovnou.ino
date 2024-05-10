#include "motor.h"

#define DB  20

void setup() {
  initMotor();
}

void loop() {
  int joystick = analogRead(A0);
  if (joystick >= 512 + DB) tocTam(255.0/(512.0 - DB)*joystick - 255.0*(512.0 + DB)/(512.0 - DB));
  else if (joystick <= 512 - DB) tocZpet(-255.0/(512.0 - DB)*joystick + 255.0);
  else zastavMotor();
}