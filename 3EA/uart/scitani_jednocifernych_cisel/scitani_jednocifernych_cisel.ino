void setup() {
  Serial.begin(9600);
}

void loop() {
  static int a = 0;
  static int b = 0;
  static int semafor = 0;
  if (Serial.available()) {
    char c = Serial.read();
    if (c >= '0' && c <= '9') {
      int n = znak_na_cislici(c);
      if (semafor == 0) {
        a = n;
        semafor = 1;
      }
      else if (semafor == 1) {
        b = n;
        Serial.print("Soucet je: ");
        Serial.println(a + b);
        semafor = 0;
      }
    } else {
      Serial.println("Nevis, co je cislice, troubo?");
    }
  }
}

int znak_na_cislici(char z) {
  return z - '0';
}