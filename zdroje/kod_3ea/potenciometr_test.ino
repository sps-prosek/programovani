
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.setCursor(0,0);
}

void loop() {
  int potenciometr = analogRead(A0);
  //Serial.println(potenciometr);
  int pozice = (potenciometr / 32);
  int pozice2 = (pozice - 16);
  static int radky = 0;
  Serial.println(pozice);


  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");

  if(pozice <= 15) {
  radky = 0;
  lcd.setCursor(pozice, radky);
  lcd.print("#");
  }

  if(pozice > 15) {
  radky = 1;
  lcd.setCursor(15 - pozice2, radky);
  lcd.print("#");
  }
  
  //Serial.println(pozice);

  delay(250);
}
