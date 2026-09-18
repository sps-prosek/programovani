#define DELKA	32

char veta[DELKA];
byte i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    veta[i] = Serial.read();
    if (veta[i] == '.' || veta[i] == '!' || veta[i] == '?') {
      vypis_vetu();
      i = 0;
    } else {
      if (i < (DELKA - 1)) i++;
      else {
        Serial.println("Veta je prilis dlouha.");
        vypis_vetu();
        i = 0;
      }
    }
  }
}

void vypis_vetu() {
  for (int j = 0; j <= i; j++) {
    Serial.write(veta[j]);
  }
  Serial.println();
}