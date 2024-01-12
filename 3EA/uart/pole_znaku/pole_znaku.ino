#define VELIKOST_POLE 3

const int velikost_pole = 3;

char pole[VELIKOST_POLE] = {'a', 'b', 'c'};

void setup() {
  Serial.begin(9600);
}

void loop() {
  static int index = 0;
  if (Serial.available()) {
    char c = Serial.read();
    pole[index] = c;
    if (++index >= VELIKOST_POLE) {
      index = 0;
      printuj(pole);
    }
  }
}

//void printuj(char _pole[]) {
void printuj(char* _pole) {
  Serial.print("pocet bytu: ");
  Serial.println(sizeof(_pole));
  for (int i = 0; i < VELIKOST_POLE; i++) {
    Serial.println(_pole[i]);
  }
}