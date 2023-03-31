#define IN1 4
#define IN2 5
#define PWM 3

byte rychlost;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  int potenciometr = analogRead(A0);
  //rychlost = potenciometr/4;
  rychlost = map(potenciometr, 0, 1023, 0, 255);
  analogWrite(PWM, rychlost);
  delay(100);
  //rychlost++;
}
