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
  
  }
}

void tikani() {
  unsigned long cas = millis();
  if (cas - cas_predtim >= 10) {
    tik = HIGH;
    cas_predtim = cas;
  } else tik = LOW;
}