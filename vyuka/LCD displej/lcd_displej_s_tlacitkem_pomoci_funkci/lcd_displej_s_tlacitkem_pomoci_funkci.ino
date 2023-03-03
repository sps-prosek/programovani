#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN_TL  4

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte cislo;
unsigned long cas_predchozi;
int tlacitko_predchozi;

void setup() {
  init_displej();
  init_tlacitko();
  cas_predchozi = millis();
}

void loop() {
  unsigned long cas = millis();

  int stav = tlacitko();

  if (stav) cislo = 0;

  if (cas - cas_predchozi >= 1000) {
    cislo++;
    displej();
    cas_predchozi = cas;
  }
}

void tlacitko() {
  int tlacitko = digitalRead(PIN_TL);
  if (tlacitko == LOW && tlacitko_predchozi == HIGH) {
    return 1;
  } else return 0;
  tlacitko_predchozi = tlacitko;
}

void init_tlacitko() {
  pinMode(PIN_TL, INPUT_PULLUP);
  tlacitko_predchozi = digitalRead(PIN_TL);
}

void init_displej() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void displej() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cislo);
}
