#include <Servo.h>

Servo moje_servo;
int pozice = 90;

void setup() {
  moje_servo.attach(3);
  moje_servo.write(pozice);
  Serial.begin(9600);
}

void loop() {
  tikani();
  if (tik) {
    if (krok < 4) krok++;
    else krok = 0;
    myservo.write(pozice[krok]);
  }
}

void tikani() {
  unsigned long cas = millis();
  if (cas - cas_predtim >= 1000) {
    tik = HIGH;
    cas_predtim = cas;
  } else tik = LOW;
}