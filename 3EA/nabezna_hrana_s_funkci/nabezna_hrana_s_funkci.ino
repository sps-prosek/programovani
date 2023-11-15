#define PIN_BTN 2 // makro pro pin tlačítka

int stav_led; // paměť pro uložení stavu LED

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP); // nastavení funkce pinu tlačítka
  pinMode(LED_BUILTIN, OUTPUT);   // nastavení funkce pinu s LED
}

void loop() {
  // načtení aktuálního stavu tlačítka
  int stav_tlacitka = !digitalRead(PIN_BTN);

  // detekce náběžné hrany
  if (nastalaNabeznaHrana(stav_tlacitka))  {
    stav_led = !stav_led; // překlopení stavu LED
  }

  // nastavení stavu LED
  digitalWrite(LED_BUILTIN, stav_led);

  delay(50);
}

int nastalaNabeznaHrana(int hodnota_ted) {
  static int _hodnota_predtim;
  int _vysledek = LOW;
  if (hodnota_ted == HIGH && _hodnota_predtim == LOW) {
    _vysledek = HIGH;
  }
  _hodnota_predtim = hodnota_ted;
  return _vysledek;
}
