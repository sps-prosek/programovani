#include "muj_motor.h"

void setup() {
  nastavMotor();
}

void loop() {
  otacejTam();
  nastavRychlost(255);
}