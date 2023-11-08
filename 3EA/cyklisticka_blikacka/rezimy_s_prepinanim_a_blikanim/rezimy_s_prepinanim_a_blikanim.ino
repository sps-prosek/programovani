#define PIN_BTN 2
#define PIN_LED 5
//#define T       1000

int tik = LOW;

void tikani();

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static int rezim = 0;
  static int stav_tlacitka_predchozi = HIGH;
  static int stav_led = LOW;
  static int T = 1000;
  int stav_tlacitka = digitalRead(PIN_BTN);
  
  tikani(T);
  
  if (stav_tlacitka == LOW && stav_tlacitka_predchozi == HIGH) {
    if (rezim < 4) rezim++;  // rezim += 1;
    else rezim = 0;
    Serial.println(rezim);
    //rezim = (rezim < 4) ? rezim++ : 0;
  }
  stav_tlacitka_predchozi = stav_tlacitka;

  switch (rezim) {
    case 0:  // LED nesvítí
      stav_led = LOW;
      digitalWrite(PIN_LED, stav_led);
      break;
    case 1:  // LED svítí souvisle
      stav_led = HIGH;
      digitalWrite(PIN_LED, stav_led);
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
      break;
    case 4:  // LED mění plynule intenzitu
      analogWrite(PIN_LED, 255.0*(sin(millis()/1000.0)+1)/2.0);
      break;
    default:  // neznámý režim

      break;
  }
}

void tikani(int T) {
  unsigned long cas = millis();
  static unsigned long cas_predtim = 0;
  if (cas - cas_predtim >= T) {
    // zmen stav LED
    tik = HIGH;
    cas_predtim = cas;
  } else tik = LOW;
}