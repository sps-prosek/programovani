#define PIN_A 2
#define PIN_B 3

void setup() {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);

  Serial.begin(115200);
}

void loop() {

  int A = digitalRead(PIN_A);
  int B = digitalRead(PIN_B);

  static int A_pred = digitalRead(PIN_A);
  static int B_pred = digitalRead(PIN_B);

  static int pozice;

  if (A == HIGH && A_pred == LOW) {

    if (B == HIGH) pozice--;
    else pozice++;
    Serial.println(pozice);

  } if (A == LOW && A_pred == HIGH) {

    if (B == HIGH) pozice++;
    else pozice--;
    Serial.println(pozice);

  }

  A_pred = A;
  B_pred = B;

}

