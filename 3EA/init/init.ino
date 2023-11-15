#define PIN_TLACITKO  2

void setup() {
  pinMode(PIN_TLACITKO, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int stav = !digitalRead(PIN_TLACITKO);
  if (stav) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}