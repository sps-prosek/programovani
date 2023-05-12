int ledPin = 13;
int dotDuration = 100;
int dashDuration = 3 * dotDuration;
int interSymbolPause = dotDuration;
int interCharacterPause = 3 * dotDuration;
int interWordPause = 7 * dotDuration;

bool isBlinking = false;
bool hasNewData = false;
String morseMessage = "";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(19200);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '/' && morseMessage.length() > 0) {
      hasNewData = true;
    } else if (c == '-' || c == '.') {
      morseMessage += c;
    }
  }

  if (hasNewData && !isBlinking) {
    isBlinking = true;
    for (int i = 0; i < morseMessage.length(); i++) {
      char c = morseMessage.charAt(i);
      if (c == '-') {
        blink(dashDuration);
      } else if (c == '.') {
        blink(dotDuration);
      }
      delay(interSymbolPause);
    }
    resetBlinking();
    Serial.println("Přenos byl dokončen.");
  }
}

void blink(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration * dotDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void resetBlinking() {
  isBlinking = false;
  hasNewData = false;
  morseMessage = "";
}