const int buttonPin = 8;
const int ledPin = 13;

bool ledState = false;
bool lastButtonState = HIGH;
bool buttonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);
}

void loop() {
  bool reading = digitalRead(buttonPin);

  // Änderung erkannt → Entprell-Timer zurücksetzen
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Wenn der Zustand länger stabil ist als debounceDelay
  if ((millis() - lastDebounceTime) > debounceDelay) {

    // Hat sich der Tasterzustand wirklich geändert?
    if (reading != buttonState) {
      buttonState = reading;

      // Taster gedrückt (LOW wegen Pull-Up)
      if (buttonState == LOW) {
        ledState = !ledState;              // LED umschalten
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastButtonState = reading;
}
