#define DEBOUNCE_TIME 	200
#define	PIN_BTN			    4

void setup() {
  
  // nastaveni rezimu digitalniho pinu
  pinMode(PIN_BTN, INPUT_PULLUP);

  // spusteni seriove linky pro komunikaci s PC
  Serial.begin(9600);

}

void loop() {

  // detekce stisku tlacitek
  byte stisknuto = tlacitko_stisknuto();
  
  // kontrola, zda bylo tlacitko stisknuto
  if (stisknuto == HIGH) {
    
    // vypsani zpravy do serioveho monitoru
    Serial.println("Stisknuto");
    
  }
}

byte tlacitko_stisknuto() {
  
  // deklarace promenne pro ulozeni predchoziho stavudigitalniho pinu do pameti
  static byte stav_predchozi;

  // deklarace promenne pro ulozeni casu detekce posledniho stisknuti
  static unsigned long cas_posledniho_stisknuti;

  // ziskani aktualniho stavu digitalniho vstupu
  byte stav = digitalRead(PIN_BTN);

  // deklarace promenne pro signalizaci stisknuti tlacitka
  byte stisknuto = LOW;

  if (stav == LOW && stav_predchozi == HIGH) {

    // kontrola uplynuti DEBOUNCE_TIME od posledniho stisknuti tlacitka
    if (millis() - cas_posledniho_stisknuti >= DEBOUNCE_TIME) stisknuto = HIGH;

    // ulozeni aktualniho casu pro pristi smycku programu
    cas_posledniho_stisknuti = millis();
  }

  // ulozeni stavu do pameti pro pristi smycku programu
  stav_predchozi = stav;

  // navraceni stavu tlacitka
  return stisknuto;
  
}