/*
Naprogramujte Arduino Uno tak, aby pomocí vestěvěné LED na pinu 13 bylo schopné vysílat Morseův kód
zaslaný přes sériovou linku z PC. Komunikace mezi PC a Arduinem UNO bude probíhat na baudové rychlosti
19200 baud/s. Morseův kód se bude zasílat pomocí znaku "-" (pomlčka) a "." (tečka). Jiné znaky budou
ignorovány. Časování Morseová kódu je následující. Tečka svítí 1 jednotku a pomlčka 3 jednotky, přičemž
mezi každou tečkou a pomlčkou je LED zhasnutá 1 jednotku. Jednotka trvá 100 ms. Pro časování není
povoleno používat funkci delay(). Během blikání bude příjem dalších znaků ignorován. Po dokončení
blikání zaslaného kódu bude do PC přes sériovou linku zaslána zpráva "Přenos byl dokončen.". Maximální
počet zaslaných znaků je 6. Každá sekvence teček a pomlček je zakončena lomítkem "/".

Například pro zaslanou zprávu "--.-/" bude LED blikat v následující sekvenci: 300 ms ON > 100 ms
OFF > 300 ms ON > 100 ms OFF > 100 ms ON > 100 ms OFF > 300 ms ON > 100 ms OFF.
*/

char pole[6];
int index;
int index_blikani;
int pocet_tiknuti;
int pocet_tiknuti_predchozi;
unsigned long cas_predchozi;

void setup()
{
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    char znak = Serial.read();
    if (znak == '.' || znak == '-' || index < 6) {
      pole[index] = znak;
      index++;
      if (index == 6) {
        pocet_tiknuti = 0;
        pocet_tiknuti_predchozi = 0;
        cas_predchozi = millis();
      }
    }
  }
  
  if (metronom()) pocet_tiknuti++;
  
  if (index == 6) {
    if (pole[index_blikani] == '.') {
      if (pocet_tiknuti - pocet_tiknuti_predchozi < 1) digitalWrite(LED_BUILTIN, HIGH);
      else {
        digitalWrite(LED_BUILTIN, LOW);
        if (pocet_tiknuti - pocet_tiknuti_predchozi > 2) {
           index_blikani++;
        	pocet_tiknuti_predchozi = pocet_tiknuti;       
        }
      }
    }
    if (pole[index_blikani] == '-') {
      if (pocet_tiknuti - pocet_tiknuti_predchozi < 3) digitalWrite(LED_BUILTIN, HIGH);
      else digitalWrite(LED_BUILTIN, LOW);
    }
    
    /*
    pocet_tiknuti_predchozi = pocet_tiknuti
    index_blikani++
    */
    
  }
  
  // jakmile doblika index = 0

}

int metronom() {
  unsigned long cas = millis();
  if (cas - cas_predchozi > 100) {
    cas_predchozi = cas;
    return HIGH;
  }
  return LOW;
}