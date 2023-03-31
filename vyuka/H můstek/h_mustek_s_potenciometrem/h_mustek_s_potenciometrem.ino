#define IN1 4
#define IN2 5
#define PWM 3

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void loop() {
  int potenciometr = analogRead(A0);
  int rychlost = map(potenciometr, 0, 1023, -255, 255);

  if (rychlost > 0) motorTam();
  else {
    rychlost = -1*rychlost;
    motorSem();
  }
  
  analogWrite(PWM, rychlost);
}

void motorTam() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void motorSem() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
