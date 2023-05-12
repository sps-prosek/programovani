#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 3);

unsigned long cas_predtim;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  cas_predtim = millis();
}

void loop() {
  if (tikani()) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("teplota: ");
    lcd.print((int)t);
    lcd.print("*C");
  }
}

bool tikani() {
  unsigned long _cas_ted = millis();
  bool _tik = LOW;
  if (_cas_ted - cas_predtim >= 2000) {
    cas_predtim = _cas_ted;
    _tik = HIGH;
  }
  return _tik;
}
