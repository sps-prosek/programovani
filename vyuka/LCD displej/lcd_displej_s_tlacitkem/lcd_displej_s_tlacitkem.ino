// knihova pro komunikaci pomoci I2C
#include <Wire.h>

// nacteni knihovny pro ovladani LCD displeje pres I2C prevodnik
#include <LiquidCrystal_I2C.h>

// nastaveni makra pro pin s pripojenym tlacitkem
#define BTN_PIN 3

// vytvoreni objektu pro komunikaci s LCD displejem
LiquidCrystal_I2C lcd(0x27, 16, 2);

// deklarace globalnich promennych
unsigned long t0;
int i = 0;
int btn_prev;

void setup() {
  // konfigurace pinu s pripojenym tlacitkem jako vstup s pull-up rezistorem
  pinMode(BTN_PIN, INPUT_PULLUP);

  // inicializace LCD displeje
  lcd.init();

  // smazani celeho LCD displeje
  lcd.clear();

  // zapnuti podsviceni LCD displeje
  lcd.backlight();

  // nastaveni kurzoru na prvni radek a prvni pozici vlevo
  lcd.setCursor(0, 0);

  // vypis textu na pozici kurzoru
  lcd.print("Cislo: ");

  // posun kurzoru na dalsi pozici
  lcd.setCursor(6, 0);

  // vypis cisla na pozici kurzoru
  lcd.print(i);

  // ziskani aktualniho poctu milisekund
  t0 = millis();

  // nacteni vychoziho stavu tlacitka
  btn_prev = digitalRead(BTN_PIN);
}

void loop() {
  // casovani pomoci millis()
  if ((millis() - t0) >= 1000 && i <= 100) {

    // volani uzivatelske funkce pro obnovu displeje
    obnov_displej();

    // aktualizace casu
    t0 = millis();
  }

  // ziskani stavu tlacitka
  int btn = digitalRead(BTN_PIN);

  // kontrola stisku tlacitka
  if (btn == LOW && btn_prev == HIGH) {

    // nulovani zobrazovane promenne
    i = 0;

    // aktualizace casu
    t0 = millis();

    // smazani LCD displeje
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Cislo: ");

    lcd.setCursor(6, 0);
    lcd.print(i);
  }

  // ulozeni stavu tlacitka do pameti
  btn_prev = btn;
}

void obnov_displej() {
  lcd.setCursor(6, 0);
  lcd.print(i);
}
