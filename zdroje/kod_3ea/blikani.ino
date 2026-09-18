// deklarace promennych

byte pocet;
byte stav_led = LOW;
unsigned long cas_predtim = 0;

void setup() {

  // inicializace seriove linky
  
  Serial.begin(9600);
  
  // inicializace vestavene LED
  
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  // kontrola dostupnosti prijatych znaku
  
  if (Serial.available()) {
  
	// nacteni nejstarsiho prijateho znaku
	
    char znak = Serial.read();
	
	// kontrola prijateho znaku (musi byt '1' az '5') a overeni, ze neprobiha blikani (tj. pocet == 0)
	
	if (pocet == 0 && znak >= '1' && znak <= '5') {
      
	  // prevod znaku na pocet (musi byt 2x vice, jelikoz 1 bliknuti je rozsviceni a zhasnuti - tj. 2 zmeny)
	  
	  pocet = 2*(znak - '0');
	  
    }
  }
  
  // ziskani aktualniho casu
  
  unsigned long cas = millis();
  
  // kontrola ubehnuteho casu a poctu bliknuti
  
  if (pocet > 0 && cas - cas_predtim >= 500) {
    
	// zmenu promenne pro nastaveni stavu LED
	
	stav_led = !stav_led;
	
	// aktualizace casu pro dalsi smycku
	
    cas_predtim = cas;
	
	// odecteni poctu po provedeni zmeny
	
    pocet--;
  }

  // nastaveni stavu LED

  digitalWrite(LED_BUILTIN, stav_led);

}