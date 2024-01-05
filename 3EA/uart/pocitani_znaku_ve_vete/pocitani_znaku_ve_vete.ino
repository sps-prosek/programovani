void setup() {

  // nastavení sériové linky
  Serial.begin(9600);
}

void loop() {
  
  // deklarace statické proměnné pro uložení počtu znaků 'a'
  static unsigned int pocet_a = 0;
  
  // kontrola přijetí znaků z PC
  if (Serial.available()) {

    // vyčtení jednoho znaku z bufferu
    char c = Serial.read();
    
    // detekce znaku 'a' a navýšení uloženého počtu
    if (c == 'a') pocet_a++;

    // detekce konce věty
    if (c == '.' || c == '!' || c == '?') {
      
      // výpis počtu znaků 'a'
      Serial.print("Pocet nalezenych znaku: ");
      Serial.println(pocet_a);
      
      // vynulování počtu znaků 'a' pro další větu
      pocet_a = 0;
    }
  }
}
