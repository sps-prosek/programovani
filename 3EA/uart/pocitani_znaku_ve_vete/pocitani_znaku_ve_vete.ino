void setup() {
  Serial.begin(9600);
}

void loop() {
  static unsigned int pocet_a = 0;
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'a') pocet_a++;
    if (c == '.' || c == '!' || c == '?') {
      Serial.print("Pocet nalezenych znaku: ");
      Serial.println(pocet_a);
    }
  }
}
