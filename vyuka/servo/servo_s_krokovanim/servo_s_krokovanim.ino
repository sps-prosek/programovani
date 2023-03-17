#include <Servo.h>

Servo myservo;
byte tik;
byte pozice[4] = { 0, 90, 180, 90 };
byte krok;

unsigned long cas_predtim;

void setup() {
  myservo.attach(9);
  cas_predtim = millis();
}

void loop() {
  tikani();
  if (tik) {
    if (krok < 4) krok++;
    else krok = 0;
    myservo.write(pozice[krok]);
  }
  /*
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  */
}

void tikani() {
  unsigned long cas = millis();
  if (cas - cas_predtim >= 1000) {
    tik = HIGH;
    cas_predtim = cas;
  } else tik = LOW;
}