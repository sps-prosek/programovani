// globalni promenne
int hlasitost;
char radek[16];

void setup() {

  // inicializace seriove linky
  Serial.begin(9600);

}

void loop() {

  // vypis poctu znaku, ktere odpovidaji aktualni hlasitosti
  Serial.println(hlasitost_na_pocet_znaku(hlasitost));
  
  // prodleva pred zmenou hlasitosti
  delay(100);

  // cyklicka zmena hlasitosti od 0 do 100
  if (hlasitost < 100) hlasitost++;
  else hlasitost = 0;

}

void napln_pole() {
  
}

// funkce prevadi hlasitost od 0 do 100 na pocet znaku od 0 do 16
int hlasitost_na_pocet_znaku(int h) {

  int _h;

  if (h < 0) _h = 0;
  else if (h > 100) _h = 100;
  else _h = h;
  
  return (_h*16)/100;

}