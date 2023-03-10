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
byte blikej;
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
	if (index < 6 && blikej == 0) {
	  if (znak == '.' || znak == '-') {
		pole[index] = znak;
		index++;
	  }
      if ((index == 6 || znak == '/') ) {
		index_blikani = 0;
        pocet_tiknuti = 0;
        pocet_tiknuti_predchozi = 0;
        cas_predchozi = millis();
		blikej = 1;
      }
    }
  }
  
  if (metronom()) pocet_tiknuti++;
  
  if (index == 6 || blikej) {
    
	if (pole[index_blikani] == '.') {
      if (pocet_tiknuti - pocet_tiknuti_predchozi < 1) digitalWrite(LED_BUILTIN, HIGH);
      else {
        digitalWrite(LED_BUILTIN, LOW);
        if (pocet_tiknuti - pocet_tiknuti_predchozi > 1) {
           index_blikani++;
        	pocet_tiknuti_predchozi = pocet_tiknuti;       
        }
      }
    }
	
	if (pole[index_blikani] == '-') {
      if (pocet_tiknuti - pocet_tiknuti_predchozi < 3) digitalWrite(LED_BUILTIN, HIGH);
      else {
        digitalWrite(LED_BUILTIN, LOW);
        if (pocet_tiknuti - pocet_tiknuti_predchozi > 3) {
           index_blikani++;
        	pocet_tiknuti_predchozi = pocet_tiknuti;       
        }
      }
    }
	
	if (index_blikani == index) {
		index = 0;
		blikej = 0;
	}
	
  }

}

int metronom() {
  unsigned long cas = millis();
  int _output = LOW;
  if (cas - cas_predchozi > 500) {
	cas_predchozi = cas;
	_output = HIGH;
  }
  return _output;
}