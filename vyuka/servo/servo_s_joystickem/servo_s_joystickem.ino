#include <Servo.h>

Servo moje_servo;
int pozice = 90;
byte tik;
unsigned long cas_predtim;

void setup() {
  moje_servo.attach(3);
  moje_servo.write(pozice);
  Serial.begin(9600);
}

void loop() {
  tikani();
  if (tik) {
    int joystick = analogRead(A0);
    if (joystick > 512 + 10) pozice++;
    else if (joystick < 512 - 10) pozice--;
    moje_servo.write(pozice);
  }
