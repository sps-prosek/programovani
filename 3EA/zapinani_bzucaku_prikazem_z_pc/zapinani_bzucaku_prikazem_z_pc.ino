#define T 1000

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  int tik = tikani();
  static int pocet = 0;
  static int rezim = LOW;
  static int stav_led = LOW;
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case '0':
        rezim = LOW;
        break;
      case '1':
        rezim = HIGH;
        pocet = 3;
        break;
    }
  }

  if (rezim) {
    if (tik) {
      if (pocet > 0) stav_led = !stav_led;
      if (stav_led == LOW) pocet--;
      if (pocet == 0) rezim = 0;
    }
  } else {
    stav_led = LOW;
  }

  //digitalWrite(LED_BUILTIN, stav_led);
  if (stav_led) tone(10, 220, 100);
}

int tikani() {
  static unsigned long cas_predtim = 0;
  unsigned long cas = millis();
  if (cas - cas_predtim >= T) {
    cas_predtim = cas;
    return HIGH;
  } else return LOW;
}