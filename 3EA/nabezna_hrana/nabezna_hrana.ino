#define PIN_BTN 2 // makro pro pin tlačítka

int predchozi_stav_tlacitka;  // "paměť" pro uložení předchozího stavu tlačítka
int stav_led; // paměť pro uložení stavu LED

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP); // nastavení funkce pinu tlačítka
  pinMode(LED_BUILTIN, OUTPUT);   // nastavení funkce pinu s LED
  predchozi_stav_tlacitka = !digitalRead(PIN_BTN);  // získání prvního stavu tlačítka
}

void loop() {
  // načtení aktuálního stavu tlačítka
  int stav_tlacitka = !digitalRead(PIN_BTN);

  // detekce náběžné hrany
  if (stav_tlacitka == HIGH && predchozi_stav_tlacitka == LOW)  {
    stav_led = !stav_led; // překlopení stavu LED
  }

  // nastavení stavu LED
  digitalWrite(LED_BUILTIN, stav_led);

  // uložení stavu tlačítka do paměti
  predchozi_stav_tlacitka = stav_tlacitka;

  delay(50);
}