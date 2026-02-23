// Programm 3 – WHILE Schleife (läuft solange Bedingung gilt)
// LED bleibt an solange Taster gedrückt
// Programm ist Teil des Grundkurses Arduino Einsteiger VHS 2026


void setup() {
  pinMode(11, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Warte auf Tastendruck...");

  while (digitalRead(8) == HIGH) {
    // tut nichts – wartet
  }

  Serial.println("Gedrückt!");

  while (digitalRead(8) == LOW) {
    digitalWrite(11, LOW);
  }

  digitalWrite(11, HIGH);
  Serial.println("Losgelassen!");
}


