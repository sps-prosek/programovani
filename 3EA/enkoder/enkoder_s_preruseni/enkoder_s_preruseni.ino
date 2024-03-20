#define PIN_DT 2
#define PIN_CLK 3

volatile int pozice;

void setup() {

  // nastaveni funkce pinu
  pinMode(PIN_DT, INPUT);
  pinMode(PIN_CLK, INPUT);

  // aktivace seriove komunikace s PC
  Serial.begin(115200);

  // spusteni detekce preruseni na pinu DT
  attachInterrupt(digitalPinToInterrupt(PIN_DT), change_DT, CHANGE);
}

void change_DT() {

  // nacteni aktualnich stavu digitalnich pinu
  int DT = digitalRead(PIN_DT);
  int CLK = digitalRead(PIN_CLK);

  // detekce nabezne hrany
  if (DT) {

    // detekce smeru
    if (CLK) pozice--;
    else pozice++;

    // detekce sestupne hrany
  } else {

    // detekce smeru
    if (CLK) pozice++;
    else pozice--;
  }
}

void loop() {
}
