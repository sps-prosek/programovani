// knihova pro komunikaci pomoci I2C
#include <Wire.h>

// nacteni knihovny pro ovladani LCD displeje pres I2C prevodnik
#include <LiquidCrystal_I2C.h>

// piny enkoderu
#define PINA  2
#define PINB  3

// vytvoreni objektu pro komunikaci s LCD displejem
LiquidCrystal_I2C lcd(0x27, 16, 2);

// deklarace globalnich promennych
unsigned long t0;
int sigA_pred = LOW;
int pocet = 0;

void setup() {
  // inicializace enkoderu
  init_enkoder();

  // inicializace LCD displeje
  lcd.init();

  // smazani celeho LCD displeje
  lcd.clear();

  // zapnuti podsviceni LCD displeje
  lcd.backlight();

  // ziskani aktualniho poctu milisekund
  t0 = millis();

}

void loop() {

  enkoder();

  // casovani pomoci millis()
  if ((millis() - t0) >= 50) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(pocet);

    // aktualizace casu
    t0 = millis();
  }
  
}

void init_enkoder() {

  // nastaveni pinu
  pinMode(PINA, INPUT);
  pinMode(PINB, INPUT);

  // nacteni pocatecniho stavu pinu
  sigA_pred = digitalRead(PINA);
}

void enkoder() {
  // ziskani stavu signalu A
  int sigA = digitalRead(PINA);
  // detekce nabezne hrany na signalu A
  if (sigA == HIGH && sigA_pred == LOW) {
    // ziskani stavu signalu B
    int sigB = digitalRead(PINB);
    // otoceni na jednu stranu
    if (sigB == HIGH) pocet++;
    // otoceni na druhou stranu
    if (sigB == LOW) pocet--;
  }
  // aktualizace predchozi hodnoty
  sigA_pred = sigA;
}
