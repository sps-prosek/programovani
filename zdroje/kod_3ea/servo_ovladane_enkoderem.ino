#define PIN_SRV 5
#define PIN_A 2
#define PIN_B 3

#include <Servo.h>

Servo moje_servo;

void setup() {
  initEnkoder();
  moje_servo.attach(PIN_SRV);
  Serial.begin(115200);
}

void loop() {
  int pozice = enkoder();
  Serial.println(pozice);
  moje_servo.write(pozice);
}

void initEnkoder() {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
}

int enkoder() {
  int A = digitalRead(PIN_A);
  int B = digitalRead(PIN_B);

  static int A_pred = digitalRead(PIN_A);
  static int B_pred = digitalRead(PIN_B);

  static int pozice;

  if (A == HIGH && A_pred == LOW) {

    if (B == HIGH) pozice = (pozice > 0) ? --pozice : pozice;
    else pozice = (pozice < 180) ? ++pozice : pozice;
  }
  if (A == LOW && A_pred == HIGH) {

    if (B == HIGH) pozice = (pozice < 180) ? ++pozice : pozice;
    else pozice = (pozice > 0) ? --pozice : pozice;
  }

  A_pred = A;
  B_pred = B;

  return pozice;
}