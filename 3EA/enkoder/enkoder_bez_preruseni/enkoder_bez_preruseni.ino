#define PIN_DT  2
#define PIN_CLK 3

void setup() {

  // nastaveni funkce pinu
  pinMode(PIN_DT, INPUT);
  pinMode(PIN_CLK, INPUT);

  // aktivace seriove komunikace s PC
  Serial.begin(115200);

}

void loop() {
  static int pozice;
  static int _DT;

  // nacteni aktualnich stavu digitalnich pinu
  int DT = digitalRead(PIN_DT);
  int CLK = digitalRead(PIN_CLK);

  // detekce zmeny na pinu DT (nabezna nebo sestupna hrana)
  if (DT != _DT) {
    
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
    
    // vypsani aktualni pozice do seriove linky
    Serial.println(pozice);
  }

  // ulozeni aktualniho stavu pinu DT pro dalsi smycku loop
  _DT = DT;
}
