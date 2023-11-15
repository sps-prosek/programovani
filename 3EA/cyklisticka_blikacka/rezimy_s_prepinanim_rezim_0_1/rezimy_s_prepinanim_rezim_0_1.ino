#define PIN_BTN 2

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  static int rezim = 0;
  static int stav_tlacitka_predchozi = HIGH;
  int stav_tlacitka = digitalRead(PIN_BTN);
  if (stav_tlacitka == LOW && stav_tlacitka_predchozi == HIGH) {
    if (rezim < 4) rezim++;  // rezim += 1;
    else rezim = 0;
    Serial.println(rezim);
    //rezim = (rezim < 4) ? rezim++ : 0;
  }
  stav_tlacitka_predchozi = stav_tlacitka;
  
  switch (rezim) {
    case 0:  // LED nesvítí
      digitalWrite(PIN_LED, LOW);
      break;
    case 1:  // LED svítí souvisle
      digitalWrite(PIN_LED, HIGH);
      break;
    case 2:  // LED bliká pomalu

      break;
    case 3:  // LED bliká rychle

      break;
    case 4:  // LED mění plynule intenzitu

      break;
    default:  // neznámý režim

      break;
  }
}