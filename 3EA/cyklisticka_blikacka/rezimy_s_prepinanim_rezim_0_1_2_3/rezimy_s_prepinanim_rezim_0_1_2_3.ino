#define PIN_BTN 2
#define PIN_LED 5

int tik = LOW;

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static int T = 1000;

  tikani(T);

  static unsigned long cas_prepnuti_na_sin = 0;
  static int stav_led = LOW;
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
      T = 1000;
      if (tik) stav_led = !stav_led;
      digitalWrite(PIN_LED, stav_led);
      break;
    case 3:  // LED bliká rychle
      T = 200;
      if (tik) stav_led = !stav_led;
      digitalWrite(PIN_LED, stav_led);
      cas_prepnuti_na_sin = millis();
      break;
    case 4:  // LED mění plynule intenzitu
      float w = 1/(2*PI);
      unsigned int intenzita;
      intenzita = 255*((-cos(w*(millis() - cas_prepnuti_na_sin)/1000)+1)/2);
      analogWrite(PIN_LED, intenzita); // 0 - 255
      break;
    default:  // neznámý režim

      break;
  }
}

void tikani(int T) {
  unsigned long cas = millis();
  static unsigned long cas_predtim = 0;
  if (cas - cas_predtim >= T) {
    tik = HIGH;
    cas_predtim = cas;
  } else tik = LOW;
}