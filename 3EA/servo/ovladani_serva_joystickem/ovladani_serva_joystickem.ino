#include <Servo.h>

Servo srv;

void setup() {
  srv.attach(9);
  srv.write(90);
}

void loop() {
  static int pozice_serva = 90;
  int pozice_joysticku = analogRead(A0);  // 0 - 1023

  if (pozice_joysticku > 512 + 20 && pozice_serva < 180) pozice_serva++;
  else if (pozice_joysticku < 512 - 20 && pozice_serva > 0) pozice_serva--;

  srv.write(pozice_serva);

  delay(50);
}
