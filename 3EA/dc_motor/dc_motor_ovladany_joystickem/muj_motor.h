#define ENA 6
#define IN1 7
#define IN2 8

void otacejTam() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void otacejSem() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void zastav() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void nastavRychlost(byte r) {
  analogWrite(ENA, r);
}

void nastavMotor() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}