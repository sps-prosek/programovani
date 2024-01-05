void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  static unsigned int stav = 0;
  static int stav_led = 0;
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case '2':
        stav = 2;
        break;
      case '1':
        stav = 1;
        stav_led = HIGH;
        break;
      case '0':
        stav = 0;
        stav_led = LOW;
        break;
      default:
        break;
    }
  }
  if (stav == 2) {
    if (tikani()) {
      stav_led = !stav_led;
    }
  }
  digitalWrite(LED_BUILTIN, stav_led);
}

int tikani() {
  static unsigned long cas_predtim = 0;
  unsigned long cas = millis();
  if (cas - cas_predtim >= 1000) {
    cas_predtim = cas;
    return 1;
  } else {
    return 0;
  }
}