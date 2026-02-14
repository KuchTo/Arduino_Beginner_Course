
//Programm 1 – IF / ELSE (Grundlogik verstehen)
// LED an wenn Taster gedrückt
// Poti steuert Helligkeit (PWM)
// Programm ist Teil des Grundkurses Arduino Einsteiger VHS 2026

void setup() {
  pinMode(11, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int taster = digitalRead(8);
  int poti = analogRead(A0);

  int helligkeit = map(poti, 0, 1023, 0, 255);

  if (taster == LOW) {
    analogWrite(11, 255 - helligkeit);   // LOW aktiv!
    Serial.println("Taster gedrückt - LED an");
  } else {
    digitalWrite(11, HIGH);
    Serial.println("Taster losgelassen - LED aus");
  }

  delay(200);
}
