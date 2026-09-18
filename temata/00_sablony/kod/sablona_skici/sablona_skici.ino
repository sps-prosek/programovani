/* ---------------------------------------------------------------------------
 * Tema:    [NN - nazev tematu]
 * Uloha:   [nazev ulohy]
 * Popis:   [co program dela - jedna az dve vety]
 *
 * Zapojeni:
 *   [LED]      -> D9 (+ rezistor 220 R na GND)
 *   [tlacitko] -> D2 (INPUT_PULLUP, druhy vyvod na GND)
 *
 * Autor:   Jaroslav Busek
 * Deska:   Arduino UNO (ATmega328P)
 * ------------------------------------------------------------------------- */

// --- piny -----------------------------------------------------------------
const uint8_t PIN_LED = 9;
const uint8_t PIN_TLACITKO = 2;

// --- konstanty ------------------------------------------------------------
const uint16_t PERIODA_MS = 500;

// --- globalni stav --------------------------------------------------------
uint32_t poslednizmena = 0;
bool stavLed = false;

// --- funkce ---------------------------------------------------------------

/* Vrati true prave jednou pri stisku tlacitka (nabezna hrana). */
bool naHrane(uint8_t pin) {
  static bool predchozi = HIGH;
  bool aktualni = digitalRead(pin);
  bool hrana = (predchozi == HIGH && aktualni == LOW);
  predchozi = aktualni;
  return hrana;
}

// --- setup / loop ---------------------------------------------------------

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TLACITKO, INPUT_PULLUP);
}

void loop() {
  uint32_t nyni = millis();

  if (nyni - poslednizmena >= PERIODA_MS) {
    poslednizmena = nyni;
    stavLed = !stavLed;
    digitalWrite(PIN_LED, stavLed);
  }

  if (naHrane(PIN_TLACITKO)) {
    Serial.println("stisk");
  }
}
