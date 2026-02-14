// Programm 3 – WHILE Schleife (läuft solange Bedingung gilt)
// LED bleibt an solange Taster gedrückt
// Programm ist Teil des Grundkurses Arduino Einsteiger VHS 2026


void setup() {
  pinMode(11, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(8) == LOW) {

    int hell;

    do {
      hell = analogRead(A0);
      hell = map(hell, 0, 1023, 0, 255);

      analogWrite(11, 255 - hell);

      Serial.print("Helligkeit: ");
      Serial.println(hell);

      delay(150);

    } while (digitalRead(8) == LOW);

    digitalWrite(11, HIGH);
  }
}


