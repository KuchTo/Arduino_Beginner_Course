void setup() {
  pinMode(11, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(8) == LOW) {

    int blinks = map(analogRead(A0), 0, 1023, 1, 20);

    for (int i = 0; i < blinks; i++) {
      digitalWrite(11, LOW);
      delay(150);
      digitalWrite(11, HIGH);
      delay(150);
    }
    while (digitalRead(8) == LOW) {
  // warten bis Taste losgelassen wird
    }
  }
}